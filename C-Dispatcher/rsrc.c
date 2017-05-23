/**
  * @author Victor Woo
  * @sid 430323825
*/


/*******************************************************************

  version: 1.0 bis (exercise 11 code template)
  date:    December 2003
  author:  Dr Ian G Graham, ian.graham@griffith.edu.au
  history:
     v1.0:     Original for exercises 11 and full project dispatcher
     v1.0 bis: Code template for exercise 11

*******************************************************************/

#include "rsrc.h"

//Checks if there are enough resouces to allocate
int rsrcChk(RsrcPtr available, Rsrc claim)
{
  if(claim.printers  <= available->printers && claim.scanners <= available->scanners && claim.modems <= available->modems  && claim.cds  <= available->cds){
    return TRUE;
  }
  return FALSE;
}

//Checks if there could be avaliable resources
int rsrcChkMax(Rsrc claim)
{
  if(claim.printers < MAX_PRINTERS && claim.scanners < MAX_SCANNERS && claim.modems <  MAX_MODEMS && claim.cds < MAX_CDS){
    return TRUE;
  }
  return FALSE;
}

//By Allocating resources to I/O we have reduce the number of avaliable resources
int rsrcAlloc(RsrcPtr available, Rsrc claim)
{
  //Checks if there is enough resources to allocate
  if(rsrcChk(available, claim) == FALSE){
    return FALSE;
  }else{
    available->printers = available->printers - claim.printers;
		available->scanners = available->scanners - claim.scanners;
		available->modems = available->modems - claim.modems;
		available->cds = available->cds - claim.cds;
    return TRUE;
  }
  return FALSE;
}

//By Freeing resources to I/O we have to increase the number of avaliable resources
void rsrcFree(RsrcPtr available, Rsrc claim)
{
  available->printers = available->printers + claim.printers;
	available->scanners = available->scanners + claim.scanners;
	available->modems = available->modems + claim.modems;
	available->cds = available->cds + claim.cds;
  return;
}
