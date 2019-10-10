#include <stdio.h>

int  //.1.
main()
{
  union { //memory for i and bytes overlap
    int i;
    char bytes[sizeof(int)];
  } u = { 0x123456 };
  printf("int = 0x%x\n", u.i);
  for (int i = 0; i < sizeof(int); i++) {
    printf("bytes[%d] at %p is 0x%02x\n",
           i, &u.bytes[i], u.bytes[i]);
  }
  return 0;
}
