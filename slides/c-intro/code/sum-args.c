#include <stdio.h>
#include <stdlib.h>

//.1.
/** Output sum of integer command-line arguments on stdout. */
int
main(int argc, const char *argv[])
{
  int sum = 0;
  for (int i = 1; i < argc; i++) {
    sum += atoi(argv[i]);
  }
  printf("%d\n", sum);
  return 0;
}
