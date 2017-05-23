/**
  * @author Victor Woo
  * @sid 430323825
*/


#ifndef PCB_H
#define PCB_H

/*******************************************************************

  version: 1.2 (exercise 11 and final project)
  date:    December 2003
  author:  Dr Ian G Graham, ian.graham@griffith.edu.au
  history:
     v1.0: Original for exercises 7, 8, & 9
     v1.1: Add reference to memory block structure for exercise 10
     v1.2: Add resource allocation

 Note: This code template is based on the original version. It is
 edited and distributed by the COMP3520 teaching staff for use
 in COMP3520 labs.

 *******************************************************************/

#include "mab.h"
#include "rsrc.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

/* process management definitions *****************************/

#define MAXARGS 3

#define DEFAULT_PROCESS "./process"

#define N_QUEUES         4  /* number of queues (including RT) */
#define RT_PRIORITY      0  //Real Time Queue Priority
#define HIGH_PRIORITY    1  //Highest Priority for User Job Queue
#define LOW_PRIORITY     (N_QUEUES - 1) //Lowest Priority for User job Queue
#define N_FB_QUEUES      (LOW_PRIORITY - HIGH_PRIORITY + 1) //Number of feedback queues

//PCB States
#define PCB_UNINITIALIZED 0
#define PCB_INITIALIZED 1
#define PCB_READY 2
#define PCB_RUNNING 3
#define PCB_SUSPENDED 4
#define PCB_TERMINATED 5

struct pcb {
    pid_t pid;
    char * args[MAXARGS];
    int arrivaltime;
    int priority;
    int remainingcputime;
    int mbytes;
    MabPtr memoryblock;
    Rsrc req;
    int status;
    struct pcb * next;
};

typedef struct pcb Pcb;
typedef Pcb * PcbPtr;

/* process management prototypes *****************************/

PcbPtr startPcb(PcbPtr);
PcbPtr suspendPcb(PcbPtr);
PcbPtr terminatePcb(PcbPtr);
PcbPtr printPcb(PcbPtr, FILE *);
void   printPcbHdr(FILE *);
PcbPtr createnullPcb();
PcbPtr enqPcb(PcbPtr, PcbPtr);
PcbPtr deqPcb(PcbPtr*);

#endif
