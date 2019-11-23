#include "fn-trace.h"
#include "x86-64_lde.h"
#include "memalloc.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

enum {
  CALL_OP = 0xE8,
  RET_FAR_OP = 0xCB,
  RET_FAR_WITH_POP_OP = 0xCA,
  RET_NEAR_OP = 0xC3,
  RET_NEAR_WITH_POP_OP = 0xC2
};

static inline bool is_call(unsigned op) { return op == CALL_OP; }
static inline bool is_ret(unsigned op) {
  return
    op == RET_NEAR_OP || op == RET_NEAR_WITH_POP_OP ||
    op == RET_FAR_OP || op == RET_FAR_WITH_POP_OP;
}
int inFnsData(void* fnPtr, FnsData *fns){
  for(int i=0;i<fns->numFns;i++){
    if(fns->fns[i].address==fnPtr){
      return i;
    }
  }
  return -1;
}

int comparator(const void *p, const void *q){ 
    FnInfo p1 = *(((FnInfo *)p)->address); 
    FnInfo q1 = *(((FnInfo *)q)->address); 
    if(p1>q1){
      return 1;
    }
    if(p1==q1){
      return 0;
    }
    return -1;
} 



/** Return pointer to opaque data structure containing collection of
 *  FnInfo's for functions which are callable directly or indirectly
 *  from the function whose address is rootFn.
 */
void traceFns(void *rootFn, FnsData *fns){
  printf("Entered\n");
  int currentIndex=fns->numFns;
  if(currentIndex==fns->size){
    if(fns->size==0){
      fns->fns = calloc(sizeof(FnInfo),1);
      fns->size=1;
    }
    else{
      fns->fns = realloc(fns->fns, 2*fns->size*sizeof(FnInfo));
      fns->size*=2;
    }
  }
  fns->numFns++;
  fns->fns[currentIndex].address=rootFn;
  fns->fns[currentIndex].nInCalls=1;
  fns->fns[currentIndex].nOutCalls=0;
  fns->fns[currentIndex].length=0;  
  unsigned char *current = rootFn;
  int currentLength = get_op_length(current);
  while(!is_ret(*current)){
    if(is_call(*current)){
      printf("Entered2\n");
      fns->fns[currentIndex].nOutCalls++;
      int offset = *(int *)(current+1);
      void *nextFn = offset+current+currentLength;
      int isIn = inFnsData(nextFn,fns);
      if(isIn==-1){
        printf("Entered3\n");
        traceFns(nextFn, fns);
      }
      else{
          fns->fns[isIn].nInCalls++;
      }
    }
    current = current + currentLength;
    currentLength = get_op_length(current);    
  }
  return;
}


const FnsData *
new_fns_data(void *rootFn)
{
  //verify assumption used when decoding call address
  assert(sizeof(int) == 4);
  FnsData *fns = NULL;
  fns = calloc(sizeof(FnsData),1);
  traceFns(rootFn, fns);
  qsort((void*)fns->fns, fns->numFns, sizeof(FnInfo), comparator);
  for(int i=0;i<fns->numFns;i++){
    printf("%p\n", fns->fns[i].address);
  }
  return fns;
}

/** Free all resources occupied by fnsData. fnsData must have been  
 *  returned by new_fns_data().  It is not ok to use to fnsData after
 *  this call.
 */
void
free_fns_data(FnsData *fnsData)
{
  free(fnsData->fns);
  free(fnsData);
}

/** Iterate over all FnInfo's in fnsData.  Make initial call with NULL
 *  lastFnInfo.  Keep calling with return value as lastFnInfo, until
 *  next_fn_info() returns NULL.  Values must be returned sorted in
 *  increasing order by fnInfoP->address.
 *
 *  Sample iteration:
 *
 *  for (FnInfo *fnInfoP = next_fn_info(fnsData, NULL); fnInfoP != NULL;
 *       fnInfoP = next_fn_info(fnsData, fnInfoP)) {
 *    //body of iteration
 *  }
 *
 */
const FnInfo *
next_fn_info(const FnsData *fnsData, const FnInfo *lastFnInfo)
{
  //@TODO
  return NULL;
}
