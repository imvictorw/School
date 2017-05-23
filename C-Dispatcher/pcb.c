/**
  * @author Victor Woo
  * @sid 430323825
*/

/********************************************************************

   version: 1.0 (exercise 7)
   date:    December 2003
   author:  Dr Ian G Graham, ian.graham@griffith.edu.au

 *******************************************************************/

#include "pcb.h"

//Starts or Resumes Process if already has started
PcbPtr startPcb (PcbPtr p) {
    if (p->pid == 0) {                 // not yet started
        switch (p->pid = fork ()) {    //  so start it
            case -1:
                perror ("startPcb");
                exit(1);
            case 0:                             // child
                p->pid = getpid();
                p->status = PCB_RUNNING;
                printf("You have started: PID(%d)\n", p->pid);
                printPcbHdr(stdout);            // printout in child to
                printPcb(p, stdout);            //  sync with o/p
                fflush(stdout);
                execvp (p->args[0], p->args);
                perror (p->args[0]);
                exit (2);
        }                                       // parent

    }
    else {
      //Resumes process
        kill (p->pid, SIGCONT);
        printf("You have been Restarted: PID(%d) \n", p->pid);
        waitpid(p->pid, NULL, WCONTINUED);
    }
    p->status = PCB_RUNNING;
    return p;
}

//Suspends the process
 PcbPtr suspendPcb(PcbPtr p) {
   int status;
    if(kill(p->pid, SIGTSTP) == -1){
      return NULL;
    }

    printf("You have been Suspended: PID(%d) \n", p->pid);
    waitpid(p->pid, &status, WUNTRACED);
    p->status = PCB_SUSPENDED;
    return p;
}

//Terminates the process
PcbPtr terminatePcb(PcbPtr p) {
    int status;
    if(kill(p->pid, SIGINT) == -1){
      return NULL;
    }

    printf("You have been terminated: PID(%d) \n", p->pid);
    waitpid(p->pid, &status, WUNTRACED);
    p->status = PCB_TERMINATED;
    return p;

}

//Print the process attributes
PcbPtr printPcb(PcbPtr p, FILE * iostream) {
    char* tmp = NULL;

    if(p->status == 0){
      tmp = "UNINITIALIZED";
    }else if(p->status == 1){
      tmp = "INITIALIZED";
    }else if(p->status == 2){
      tmp = "READY";
    }else if(p->status == 3){
      tmp = "RUNNING";
    }else if(p->status == 4){
      tmp = "SUSPENDED";
    }else if(p->status == 5){
      tmp = "TERMINATED";
    }

    fprintf(iostream, "   %d      %d     %d    %d    %d    %d    %d    %d   %d  %s\n" , p->arrivaltime, p->priority, p->remainingcputime, p->memoryblock->offset, p->mbytes, p->req.printers, p->req.scanners, p->req.modems, p->req.cds, tmp);
    return p;
}

//Print the process title for each attributes
void printPcbHdr(FILE * iostream){
  fprintf(iostream, "Arrive Priorty CPU Offset Mbytes Prn Scn Modem CDS Status\n");
}

//Creates an inactive NULL PCB
PcbPtr createnullPcb() {
    PcbPtr newprocessPtr;

    if ((newprocessPtr = (PcbPtr) malloc (sizeof(Pcb)))) {
        newprocessPtr->pid = 0;
        newprocessPtr->args[0] = DEFAULT_PROCESS;
        newprocessPtr->args[1] = NULL;
        newprocessPtr->arrivaltime = 0;
        newprocessPtr->priority = HIGH_PRIORITY;
        newprocessPtr->remainingcputime = 0;
        newprocessPtr->mbytes = 0;
        newprocessPtr->memoryblock = NULL;
        newprocessPtr->req.printers = 0;
        newprocessPtr->req.scanners = 0;
        newprocessPtr->req.modems = 0;
        newprocessPtr->req.cds = 0;
        newprocessPtr->status = PCB_UNINITIALIZED;
        newprocessPtr->next = NULL;
        return newprocessPtr;
    }
    perror("allocating memory for new process");
    return NULL;
}

//Queues process to the end of the queue
PcbPtr enqPcb(PcbPtr q, PcbPtr p) {
    PcbPtr h = q;

    p->next = NULL;
    //Goes through the queue until q->next reaches NULL
    //Then sets the NULL memory space as the PcbPtr p
    if (q) {
        while (q->next) q = q->next;
        q->next = p;
        return h;
    }
    return p;
}

//Dequeue the pointer at the head of the queue
PcbPtr deqPcb(PcbPtr * hPtr) {
    PcbPtr p;

    if (hPtr && (p = * hPtr)) {
        * hPtr = p->next;
        return p;
    }
    return NULL;
}
