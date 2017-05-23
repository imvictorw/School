/**
  * @author Victor Woo
  * @sid 430323825
*/


#ifndef RSRC_H
#define RSRC_H
/*******************************************************************

 version: 1.0 bis (exercise 11 code template)
 date:    December 2003
 author:  Dr Ian G Graham, ian.graham@griffith.edu.au
 history:
     v1.0:     Original for exercises 11 and full project dispatcher
     v1.0 bis: Code template for exercise 11

*******************************************************************/
#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

/* Resource management *****************************/

#define MAX_PRINTERS 2
#define MAX_SCANNERS 1
#define MAX_MODEMS 1
#define MAX_CDS 2

struct rsrc {
    int printers;
    int scanners;
    int modems;
    int cds;
};

typedef struct rsrc Rsrc;
typedef Rsrc * RsrcPtr;

/* prototypes  ************************************/

int rsrcChk(RsrcPtr, Rsrc);
int rsrcChkMax(Rsrc);
int rsrcAlloc(RsrcPtr, Rsrc);
void rsrcFree(RsrcPtr,Rsrc);

#endif
