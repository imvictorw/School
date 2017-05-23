/**
  * @author Victor Woo
  * @sid 430323825
*/


/*******************************************************************

version: 1.0 (exercise 7)
date:    December 2003
author:  Dr Ian G Graham, ian.graham@griffith.edu.au

*******************************************************************/

#include "hostd.h"

#define VERSION "1.0"

char * StripPath(char*);
void PrintUsage(FILE *, char *);
void SysErrMsg(char *, char *);
void ErrMsg(char *, char *);



int checkRsrc(PcbPtr process)
{

    /*
    * If the process is in the Real time queue
    * Checks that it does not take more than the maximum allocated bytes (64)
    * Checks that it does not allocate any I/O Resources
    */

    if(process->priority == 0){
      if(process->mbytes > RT_MEMORY_SIZE || process->req.printers > 0 || process->req.scanners > 0 || process->req.modems > 0 || process->req.cds > 0){
        return 1;
      }
    }

    /*
    * If the process is in the User Job Queue
    * Checks that it does not take more than the maximum allocated bytes (960)
    * Checks that it allocation of I/O Resources does not exceed the maximum I/O's given
    */

    if(process->priority > 0 && process->priority < 4){
      if(process->mbytes > USER_MEMORY_SIZE || process->req.printers > MAX_PRINTERS || process->req.scanners > MAX_SCANNERS || process->req.modems > MAX_MODEMS || process->req.cds > MAX_CDS){
        return 2;
      }
    }
    return 0;
}

int main (int argc, char *argv[]) {
    char * inputfile;             // job dispatch file
    FILE * inputliststream;
    PcbPtr inputqueue = NULL;     // input queue buffer
    PcbPtr currentprocess = NULL; // current process
    PcbPtr process = NULL;        // working pcb pointer
    PcbPtr fbqueue[3];            //Feedback Queue x3
    PcbPtr ujqueue = NULL;        // User Job queue
    PcbPtr rtqueue = NULL;        // Real Time queue

    //Allocating Feedback queue memory
    MabPtr block = malloc(sizeof(Mab));
  	block->offset = 64;
  	block->size = USER_MEMORY_SIZE;
  	block->allocated = 0;
  	block->next = block->prev = NULL;

    //Allocating Real time Memory
    MabPtr rtblock = malloc(sizeof(Mab));
  	rtblock->offset = 0;
  	rtblock->size = RT_MEMORY_SIZE;
  	rtblock->allocated = 0;
  	rtblock->next = block->prev = NULL;

    //Assigning resources block
    RsrcPtr io = malloc(sizeof(Rsrc));
    io->printers = MAX_PRINTERS;
    io->scanners = MAX_SCANNERS;
    io->modems =  MAX_MODEMS;
    io->cds = MAX_CDS;


    //Initalising every queue as NULL
    for(int i = 0; i < 3; i++){
      fbqueue[i] = NULL;
    }

    int timer = 0; //Initiating the timer

    //Checking for an input file. If there is set the name as inputfile
    if (argc == 2) inputfile = argv[1];
    else PrintUsage (stderr, argv[0]);


    /*
     * Attemps to read the inputfile
     * Prints out an error if the file could not be open
    */
    if (!(inputliststream = fopen(inputfile, "r"))) { // open it
        SysErrMsg("could not open dispatch list file:", inputfile);
        exit(2);
    }

    /*
     * Reading through every line of the inputfile,
     * It retrieves the pcb, memory and resources data from the input line
     * If an error occurs, free the process
    */
    while (1) {
        int val_check;
        process = createnullPcb();
        if ((val_check = fscanf(inputliststream, "%d, %d, %d, %d, %d, %d, %d, %d",
          &(process->arrivaltime), &(process->priority),
          &(process->remainingcputime), &(process->mbytes),
          &(process->req.printers), &(process->req.scanners),
          &(process->req.modems), &(process->req.cds))) == 8) {
            process->status = PCB_INITIALIZED;
            inputqueue = enqPcb(inputqueue, process);
        }
        else if (val_check >= 0){
            free(process);
            ErrMsg("Invalid input file", inputfile);
            exit(2);
        }
        else if (ferror(inputliststream)) {
            free(process);
            SysErrMsg("Error reading input file", inputfile);
            exit(2);
        }
        else {
            free(process);
            break;
        }
    }

  //If there is any process in any of the queues
   while (inputqueue != NULL || fbqueue[0] != NULL || fbqueue[1] != NULL || fbqueue[2] != NULL || currentprocess != NULL || ujqueue != NULL || rtqueue != NULL) {

     /*
     *  If there is any process in the inputqueue and the process has arrived before or now
     *  Check for resources errors
     *  Enqueue it to the appriopriate queue (Realtime or User Job)
     */

     while( inputqueue != NULL && inputqueue->arrivaltime <= timer){
       PcbPtr temp = deqPcb(&inputqueue);

       //CHeck if job is valid if yes then do this if not return error
       int jobcheck = checkRsrc(temp);
       if(jobcheck != 0){

         if(jobcheck == 1){
           printf("Real Time Process Allocation or Memory Error\n");
         }else if(jobcheck == 2){
           printf("User Job Process Allocation or Memory Error\n");
         }

         free(temp);
         temp = NULL;
       }else{
         /*
          * If no error, enqueue the process to the appriopriate queue
          * 0 - Real Time Queue
          * 1-3 - User Job Queue
         */
         if(temp->priority == RT_PRIORITY){
           temp->memoryblock = memAlloc(rtblock, RT_MEMORY_SIZE);
           rtqueue = enqPcb(rtqueue, temp);
         }else{
           ujqueue = enqPcb(ujqueue, temp);
         }
       }
     }

     /*
     *  If there is any process in the userjob queue & the memory block has enough space for the process & the resource block has enough space for the process
     *  Allocates memory and resources for the process
     *  Enqueue it to the appriopriate feedback queue
     */

     while(ujqueue != NULL && memChk(block, ujqueue->mbytes) != NULL && rsrcChk(io, ujqueue->req) == TRUE){

       PcbPtr tmp = deqPcb(&ujqueue);

       //Allocating and checking if there is enough memory
       MabPtr Mabtmp = memChk(block, tmp->mbytes);
       tmp->memoryblock = memAlloc(Mabtmp, tmp->mbytes);

       //Allocating I/O resources
       rsrcAlloc(io, tmp->req);

       //Error Checking to see if priority is between 1 - 3 for the priority queue
       if(tmp->priority > LOW_PRIORITY || tmp->priority < 1){
         perror("Incorrent Priority");
         exit(1);
       }

       //Enqueuing back to the appriopriate queue
       fbqueue[tmp->priority - 1] = enqPcb(fbqueue[tmp->priority - 1], tmp);
     }

     /*
     *  If there current process is running, decrement the process's timer
     *  If current process's cpu time is 0 then free the current process including its resources and memory
     *  If current process's cpu time is more than 0 and there are processes waiting in any of the queues
     *  Suspend the current process if it isnt in the real time queue, reduce the priority if its not already a LOW PRIORITY and enqueue it back to the appropriate queue
     */

    if(currentprocess != NULL && currentprocess->status == PCB_RUNNING){
       currentprocess->remainingcputime -= QUANTUM;

       /*
        * If the cpu time for the process is 0
        * 1. Terminate the current process
        * 2. Free the currentprocess's memory and resources if it isnt in the real time queue
        * 3. Free the current process
       */

       if(currentprocess->remainingcputime <= 0){
         currentprocess = terminatePcb(currentprocess);
         if(currentprocess->priority != 0){
            memFree(currentprocess->memoryblock);
            rsrcFree(io, currentprocess->req);
          }
         free(currentprocess);
         currentprocess = NULL;

         /*
          * If there is any process remaining in any of the feedback queues and the cpu time for the process is not 0
          * If its a process in the real time queue, then let it continue running until it is finish
          * If it is a user job queue -
          *    1. Suspend the current process.
          *    2. Decrease the current process's priority if it isnt in the lowest priority queue
          *    3. Enqueue the process back to the appriopriate feedback queue.
         */
         
       }else if(rtqueue != NULL || fbqueue[0] != NULL || fbqueue[1] != NULL || fbqueue[2] != NULL){
         if(currentprocess->priority > 0){
           currentprocess = suspendPcb(currentprocess);

           //Reduce Priority
           if(currentprocess->priority < 3){
             currentprocess->priority++;
           }

           //Enqueue it back to appriopriate queue
           fbqueue[currentprocess->priority - 1] = enqPcb(fbqueue[currentprocess->priority - 1], currentprocess);

           currentprocess = NULL;
          }
        }
    }

    /*
    *  Dequeue a process from the highest priority queue that is not empty
    *  Set it as current process, increment the timer and restart the whole process again until there is no more processes in any of the process queues
    */

    PcbPtr tmp;
    if(currentprocess == NULL && rtqueue != NULL){
      tmp = deqPcb(&rtqueue);

      if(tmp != NULL){
        currentprocess = startPcb(tmp);
      }
    }else if(currentprocess == NULL && fbqueue[0] != NULL){
      tmp = deqPcb(&fbqueue[0]);

      if(tmp != NULL){
        currentprocess = startPcb(tmp);
      }
    }else if(currentprocess == NULL && fbqueue[1] != NULL){
      tmp = deqPcb(&fbqueue[1]);

      if(tmp != NULL){
        currentprocess = startPcb(tmp);
      }
    }else if(currentprocess == NULL && fbqueue[2] != NULL){
      tmp = deqPcb(&fbqueue[2]);

      if(tmp != NULL){
        currentprocess = startPcb(tmp);
      }
    }

    sleep(1);
    timer += QUANTUM;

  }

  /*  Memory Freeing  */
  block = memFree(block);
  rtblock = memFree(rtblock);
  free(io);
  exit (0);

}


//Strip path from file name
char * StripPath(char * pathname) {
    char * filename = pathname;\

    if (filename && *filename) {           // non-zero length string
        filename = strrchr(filename, '/'); // look for last '/'
        if (filename)                      // found it
            if (*(++filename))             //  AND file name exists
                return filename;
            else
                return NULL;
        else
            return pathname;               // no '/' but non-zero length string
    }                                      // original must be file name only
    return NULL;
}

//Prints if there is no input file usage
void PrintUsage(FILE * stream, char * progname) {
    if (!(progname = StripPath(progname))) {
        progname = DEFAULT_NAME;
    }

    fprintf(stream,"\n"
      "%s process dispatcher (version " VERSION "); usage:\n\n"
      "  %s <dispatch file>\n"
      " \n"
      "  where <dispatch file> is list of process parameters \n\n",
      progname,progname);

    exit(127);
}


//Prints an error message only
void ErrMsg(char * msg1, char * msg2) {
    if (msg2) {
        fprintf(stderr,"ERROR - %s %s\n", msg1, msg2);
    }
    else {
        fprintf(stderr,"ERROR - %s\n", msg1);
    }
    return;
}

//Prints an error and system message
void SysErrMsg(char * msg1, char * msg2) {
    if (msg2) {
        fprintf(stderr,"ERROR - %s %s; ", msg1, msg2);
    }
    else {
        fprintf(stderr,"ERROR - %s; ", msg1);
    }
    perror(NULL);
    return;
}
