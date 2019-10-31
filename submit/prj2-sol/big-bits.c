#include "big-bits.h"
#include "hex-util.h"
#include<stdio.h>
#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>


/** Provide concrete definition for struct BigBits to flesh out
 *  abstract BigBits data type.
 */
struct BigBits {
  char nibble;
  BigBits* nextNibble;
};





/** Counts the number of hex digits stored in the whole number by summing the number of nibbles used in each of the BigBits
*/
int numHexets(const BigBits *bb){
  int count=0;
  while(bb!=NULL){
    count++;
    bb=bb->nextNibble;
  }
  return count;
}

BigBits* normalizeBigBits(BigBits *bb){
  while(bb->nextNibble!=NULL && bb->nibble==0){
    BigBits *temp=bb->nextNibble;
    free(bb);
    bb=temp;
  }
  return bb;
}


/** Return a pointer to a representation of a big integer with value
 *  corresponding to the non-empty hexadecimal string hex.  Note that
 *  hex will only contain hexadecimal characters '0' - '9', 'a' - 'f'
 *  and 'A' - 'F' terminated by a NUL '\0' char.
 *
 *  The string hex may not remain valid after this function returns.
 *
 *  Returns NULL on error with errno set "appropriately".
 */
const BigBits *
newBigBits(const char *hex)
{
  BigBits *start;
  assert(CHAR_BIT == 8);
  if(strlen(hex)==0){
    start=NULL;
  }
  else{
    start=calloc(1,sizeof(BigBits));
    BigBits *current=start;
    while(*hex!='\0'){
      current->nibble=(char)charToHexet(*hex);
      if(*(hex+1)!='\0') current->nextNibble=calloc(1,sizeof(BigBits));
      current=current->nextNibble;  
      hex++;
    }
  }
  //@TODO
  return normalizeBigBits(start);
}


/** Frees all resources used by currently valid bigBits.  bigBits
 *  is not valid after this function returns.
 */
void
freeBigBits(BigBits *bigBits)
{
  while(bigBits!=NULL){
    BigBits *next=bigBits->nextNibble;
    free(bigBits);
    bigBits=next;
  }
}


/** Return a lower-case hex string representing bigBits. Returned
 *  string should not contain any non-significant leading zeros.
 *  Returns NULL on error with errno set "appropriately".  (Note that
 *  there is no call to free the corresponding string).
 */
const char *
stringBigBits(const BigBits *bigBits)
{
  char *str;
  int len=numHexets(bigBits);
  if(len==0){
    str=NULL;
  }
  else{
    str=calloc(1,(sizeof(char)*len)+1);
    str[len]='\0';
    BigBits *current=(BigBits*)bigBits;
    int index=0;
    while(current!=NULL){
      str[index++]=hexetToChar(current->nibble);
      current=current->nextNibble;
    }
    for(;*str=='0' && *(str+1)=='0'; str++){}
  }
  return str;
}



/** Return a new BigBits which is the bitwise-& of bigBits1 and bigBits2.
 *  Returns NULL on error with errno set "appropriately".
 */
const BigBits *
andBigBits(const BigBits *bigBits1, const BigBits *bigBits2)
{
  BigBits *result,*op1,*op2;
  op1=(BigBits*)bigBits1;
  op2=(BigBits*)bigBits2;
  int len1=numHexets(bigBits1);
  int len2=numHexets(bigBits2);
  int diff=len1-len2;
  if(len1==0 || len2==0){
    result=NULL;
  }
  else{
    if(diff<0){
      op1=(BigBits*)bigBits2;
      op2=(BigBits*)bigBits1;
      diff=len2-len1;
    }
    for(int i=0;i<diff;i++){
      op1=op1->nextNibble;
    }
    result=calloc(1,sizeof(BigBits));
    BigBits *current=result;
    while(op1!=NULL && op2!=NULL){
      current->nibble= op1->nibble&op2->nibble;
      if((op1->nextNibble!=NULL) && (op2->nextNibble!=NULL)){
        current->nextNibble=calloc(1,sizeof(BigBits));
        current=current->nextNibble;
      }
      op1=op1->nextNibble;
      op2=op2->nextNibble;
    }
  }
  return ((const BigBits*)normalizeBigBits(result));
}




/** Return a new BigBits which is the bitwise-| of bigBits1 and bigBits2.
 *  Returns NULL on error with errno set "appropriately".
 */
const BigBits *
orBigBits(const BigBits *bigBits1, const BigBits *bigBits2)
{
  BigBits *result,*op1,*op2;
  op1=(BigBits*)bigBits1;
  op2=(BigBits*)bigBits2;
  int len1=numHexets(bigBits1);
  int len2=numHexets(bigBits2);
  int diff=len1-len2;
  if(len1==0 || len2==0){
    return NULL;
  }
  else{
    if(diff<0){
      op1=(BigBits*)bigBits2;
      op2=(BigBits*)bigBits1;
      diff=len2-len1;
    }
    result=calloc(1,sizeof(BigBits));
    BigBits *current=result;
    for(int i=0;i<diff;i++){
      current->nibble=op1->nibble;
      op1=op1->nextNibble;
      current->nextNibble=calloc(1,sizeof(BigBits));
      current=current->nextNibble;
    }
    while(op1!=NULL && op2!=NULL){
      current->nibble=op1->nibble|op2->nibble;
      if((op1->nextNibble!=NULL) && (op2->nextNibble!=NULL)) current->nextNibble=calloc(1,sizeof(BigBits));
      current=current->nextNibble;
      op1=op1->nextNibble;
      op2=op2->nextNibble;
    }
  }
  return((const BigBits*)normalizeBigBits(result));
}


/** Return a new BigBits which is the bitwise-^ of bigBits1 and bigBits2.
 *  Returns NULL on error with errno set "appropriately".
 */
const BigBits *
xorBigBits(const BigBits *bigBits1, const BigBits *bigBits2)
{
  BigBits *result,*op1,*op2;
  op1=(BigBits*)bigBits1;
  op2=(BigBits*)bigBits2;
  int len1=numHexets(bigBits1);
  int len2=numHexets(bigBits2);
  int diff=len1-len2;
  if(len1==0 || len2==0){
    return NULL;
  }
  else{
    if(diff<0){
      op1=(BigBits*)bigBits2;
      op2=(BigBits*)bigBits1;
      diff=len2-len1;
    }
    result=calloc(1,sizeof(BigBits));
    BigBits *current=result;
    for(int i=0;i<diff;i++){
      current->nibble=op1->nibble;
      op1=op1->nextNibble;
      current->nextNibble=calloc(1,sizeof(BigBits));
      current=current->nextNibble;
    }
    while(op1!=NULL && op2!=NULL){
      current->nibble=op1->nibble^op2->nibble;
      if((op1->nextNibble!=NULL) && (op2->nextNibble!=NULL)) current->nextNibble=calloc(1,sizeof(BigBits));
      current=current->nextNibble;
      op1=op1->nextNibble;
      op2=op2->nextNibble;
    }
  }
  return((const BigBits*)normalizeBigBits(result));
}
