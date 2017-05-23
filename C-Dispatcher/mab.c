/**
  * @author Victor Woo
  * @sid 430323825
*/


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

#include "mab.h"

//Checks through the memory block until it finds the first unallocated memory block which can allocate the process memory size.
MabPtr memChk(MabPtr arena, int size)
{
  //If there is no memory pointer then return NULL
    while(arena != NULL){
      if(arena->allocated == 0){
        if(arena->size >= size){
          return arena;
        }
    }
      arena = arena->next;
    }
    return NULL;
}


//Allocates memory, if the memory block is larger than the memory needed, then it will split the block into one block which contains the process and the other which is unallocated memory
MabPtr memAlloc(MabPtr arena, int size)
{

    //If there is no memory pointer then return NULL
    if( arena == NULL ){
      return NULL;
    }

    //Checks if the process's memory size can fit in the given size
    if(arena->size > size){
      arena = memSplit(arena, size);

      //If split, the block next to it will be unallocated
      arena->next->allocated = 0;
    }

    //Set the process's memory space as allocated
    arena->allocated = 1;
    return arena;

}

//Frees allocated process memory from the memory block
MabPtr memFree(MabPtr m)
{
  //If there is no memory pointer then return NULL
    if(m == NULL){
      return NULL;
    }

    //Sets the process as unallocated
    m->allocated = 0;

    //If there are blocks which are connected, merge the blocks back to 1 contiguious block
    if(m->next != NULL && m->next->allocated == 0){
      m = memMerge(m);
    }

    if(m->prev != NULL && m->prev->allocated == 0){
      m = memMerge(m->prev);
    }

  return m;

}

//Merge blocks between the given block and the adjacent block
MabPtr memMerge(MabPtr m)
{

  MabPtr right = m->next;

  //If there is no memory pointer then return NULL
  if(m == NULL){
    return NULL;
  }

  //Checks if the process given has a block right of its own and if its allocated
  if(right != NULL && right->allocated == 0){
    m->size = m->size + right->size; // Add the sizes of the right and its on together
    m->next = right->next;  //Sets the next block as the right's block. If the current process's block and the right are being merged together then the next block should be the right's next.

    //Now the block has been merged, the next's previous should link back to the process's merged block because at the moment it is linked to the old right address
    if(right->next != NULL){
      (right->next)->prev = m;
    }

    //Deleting the Memory Allocation Block
    free(right);
    right = NULL;
    return m;
  }

  return m;

}

//Splits the memory into two blocks, one with size size(given in the function). The other is the leftover size from the memory block which was split
MabPtr memSplit(MabPtr m, int size)
{

  //If there is no memory pointer then return NULL
  if(m == NULL){
    return NULL;
  }

  //Initiatizing the Memory Allocation Block, setting the offset and size
  MabPtr right = malloc(sizeof(Mab));
  right->offset = m->offset + size; //Offset of the block will change since we are splitting the block
  right->size = m->size - size; // The split block is the splitting the block minus the size it wants to split

  m->size = size; //Changes the size of the memory block to fit the process's memory size and mark it as allocate
  m->allocated = 1;

  //Fix up the connections between the split memory blocks
  right->next = m->next;
  right->prev = m;

  if(m->next != NULL){
    (right->next)->prev = right;
  }
  m->next = right;

  return m;
}

//Prints content of the memory offset, size and the process is allocated
void memPrint(MabPtr arena)
{
    while(arena) {
        printf("offset%7d: size%7d - ",arena->offset, arena->size);
        if (arena->allocated) printf("allocated\n");
        else printf("free\n");
        arena = arena->next;
    }
}
