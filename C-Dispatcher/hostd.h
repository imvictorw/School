/**
  * @author Victor Woo
  * @sid 430323825
*/

#ifndef GHOST_H
#define GHOST_H
/*******************************************************************

  version: 1.2 bis (exercise 10 & 11 code template)
  date:    December 2003
  author:  Dr Ian G Graham, ian.graham@griffith.edu.au
  history:
     v1.0:     original for exercises 7, 8 & 9
     v1.1:     add memory allocation (exercise 10)
     v1.2:     add resource allocation
     v1.2 bis: code template for exercises 10 & 11

 Note: This code template is based on the original version. It is
 edited and distributed by the COMP3520 teaching staff for use
 in COMP3520 labs.

 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

#include "pcb.h"
#include "mab.h"
#include "rsrc.h"

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#define DEFAULT_NAME "hostd"
#define QUANTUM  1
#endif
