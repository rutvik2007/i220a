#include <stdio.h>
#include <stdlib.h>

static void //.1.
bases(long values[], int nValues)
{
  for (int i = 0; i < nValues; i++) {
    long v = values[i];
    printf("number: %ld == 0%lo == 0X%lX == 0x%lx\n",
           v, v, v, v);
  }
}

//.2.
int
main()
{
  long values1[] = { 75, 123, 99 };
  long values2[] = { 075, 0x123, 0x99 };
  bases(values1, sizeof(values1)/sizeof(values1[0]));
  bases(values2, sizeof(values2)/sizeof(values2[0]));
  return 0;
}
