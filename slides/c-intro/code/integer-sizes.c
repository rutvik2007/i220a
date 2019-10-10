#include <stdio.h>

int
main()
{
  //concatenation of adjacent string literals
  //%ld not portable; modern C allows %zu for sizeof()
  printf("sizeof(char) = %ld, sizeof(short) = %ld, "
         "sizeof(int) = %ld sizeof(long) = %ld, "
         "sizeof(long long) = %ld\n",
         sizeof(char), sizeof(short), sizeof(int),
         sizeof(long), sizeof(long long));
  return 0;
}
