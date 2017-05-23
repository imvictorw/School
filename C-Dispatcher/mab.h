/**
  * @author Victor Woo
  * @sid 430323825
*/


#ifndef MAB_H
#define MAB_H

/********************************************************************

  version: 1.0 bis (exercises 10 & 11 code template)
  date:    December 2003
  author:  Dr Ian G Graham, ian.graham@griffith.edu.au
  history:
     v1.0:     Original for exercise 10
     v1.0 bis: Code template for exercises 10 & 11

 Note: This code template is based on the original version. It is
       edited and distributed by the COMP3520 teaching staff for use
       in COMP3520 labs.

*******************************************************************/

#include <stdlib.h>
#include <stdio.h>

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

/* memory management *******************************/

#define MEMORY_SIZE       1024  //Size of the memory block given
#define RT_MEMORY_SIZE    64    //Size of memory for Real time queue
#define USER_MEMORY_SIZE  (MEMORY_SIZE - RT_MEMORY_SIZE) //Size of memory for User job Queue

struct mab {
    int offset;
    int size;
    int allocated;
    struct mab * next;
    struct mab * prev;
};

typedef struct mab Mab;
typedef Mab * MabPtr;

/* memory management function prototypes ********/

MabPtr memChk(MabPtr, int);
MabPtr memAlloc(MabPtr, int);
MabPtr memFree(MabPtr);
MabPtr memMerge(MabPtr);
MabPtr memSplit(MabPtr, int);
void   memPrint(MabPtr);
#endif
