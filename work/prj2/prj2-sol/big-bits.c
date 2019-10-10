#include "big-bits.h"
#include "hex-util.h"

#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>


/** Provide concrete definition for struct BigBits to flesh out
 *  abstract BigBits data type.
 */
struct BigBits {
  char byte;
  BigBits* nextByte;
  char nibblesUsed;
};

typedef struct CharByte{
  char hexets[2];
  int numHexets;
}CharByte;

CharByte getCharsFromByte(BigBits *bigbit){
  CharByte cb;
  cb.numHexets=0;
  if(bigbit->nibblesUsed==2){
    cb.numHexets=2;
    
  }
}

/** Counts the number of hex digits stored in the whole number by summing the number of nibbles used in each of the BigBits
*/
int numHexets(const BigBits *bb){
  int count=0;
  while(bb!=NULL){
    count+=bb->nibblesUsed;
    bb=bb->nextByte;
  }
  return count;
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
  BigBits *current;
  assert(CHAR_BIT == 8);
  if(strlen(hex)==0){
    current=NULL;
  }
  else{
    current=calloc(1,sizeof(BigBits));
    while(*hex!='\0'){
      if(current->nibblesUsed==2){
        current->nextByte=calloc(1,sizeof(BigBits));
        current=current->nextByte;
      }
      current->byte+=charToHexet(*hex);
      if(current->nibblesUsed==0){
      current->byte<<=4;
      }
      current->nibblesUsed++;    
    }
    hex++;
  }
  //@TODO
  return current;
}


/** Frees all resources used by currently valid bigBits.  bigBits
 *  is not valid after this function returns.
 */
void
freeBigBits(BigBits *bigBits)
{
  while(bigBits!=NULL){
    BigBits *next=bigBits->nextByte;
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
      if(current->nibblesUsed==2){
        str[index++]=hexetToChar((int)((current->byte&0xf0)>>4));
        str[index++]=hexetToChar((int)(current->byte&0x0f));
      }
      else if(current->nibblesUsed==1){
        str[index++]=hexetToChar((int) ((current->byte&0xf0)>>4));
      }
      current=current->nextByte;
    }
  }
  return str;
}


/** Return a new BigBits which is the bitwise-& of bigBits1 and bigBits2.
 *  Returns NULL on error with errno set "appropriately".
 */
const BigBits *
andBigBits(const BigBits *bigBits1, const BigBits *bigBits2)
{
  BigBits *result=NULL;
  int len1=numHexets(bigBits1);
  int len2=numHexets(bigBits2);
  int lenResult=(len1>len2?len1:len2);
  char *hex=calloc(1,(sizeof(char)*lenResult)+1);
  hex[lenResult]='\0';
  if(len1>len2){
    for(int i=0;i<len1-len2;i++){
      hex[i]='0';
    }

  }
  return result;
}


/** Return a new BigBits which is the bitwise-| of bigBits1 and bigBits2.
 *  Returns NULL on error with errno set "appropriately".
 */
const BigBits *
orBigBits(const BigBits *bigBits1, const BigBits *bigBits2)
{
  //const BigBits *result=calloc(1,(numHexets))

  return NULL;
}


/** Return a new BigBits which is the bitwise-^ of bigBits1 and bigBits2.
 *  Returns NULL on error with errno set "appropriately".
 */
const BigBits *
xorBigBits(const BigBits *bigBits1, const BigBits *bigBits2)
{
  //@TODO
  return NULL;
}
