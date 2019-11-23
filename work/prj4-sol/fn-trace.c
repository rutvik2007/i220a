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

unsigned long power(char c, unsigned long n){
  unsigned long retVal = c;
  for(int i=0; i<n*8; i++){
    retVal*=2;
  }
  return retVal;
}
/** Return pointer to opaque data structure containing collection of
 *  FnInfo's for functions which are callable directly or indirectly
 *  from the function whose address is rootFn.
 */
void traceFns(void *rootFn, FnsData *fns){
    unsigned char *current = rootFn;
    int currentLength = get_op_length(current);
    while(!(currentLength<0)){
    if(is_ret(*current)) return;
    else if(is_call(*current)){
      if(fns == NULL){
        fns = calloc(sizeof(FnsData),1);
        fns -> numFns = 1;  
      }
      unsigned long addr=0;
      for(int i=1; i<currentLength; i++){
        unsigned char c = *(current+i);
        addr+=power(c,currentLength-i-2);
      }
      printf("%xl\n", addr);
      traceFns((void *)addr, fns);
    }
    current = current + currentLength;
    currentLength = get_op_length(current);  
    //for(int i=0; i<currentLength; i++){
    //  unsigned char c = *(current+i);
      //printf("%x ", c);
    //}
        
  }
  //return NULL;
}

const FnsData *
new_fns_data(void *rootFn)
{
  //verify assumption used when decoding call address
  assert(sizeof(int) == 4);
  FnsData *fns = NULL;
  traceFns(rootFn, fns);
  return fns;
}

/** Free all resources occupied by fnsData. fnsData must have been
 *  returned by new_fns_data().  It is not ok to use to fnsData after
 *  this call.
 */
void
free_fns_data(FnsData *fnsData)
{
  //@TODO
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
