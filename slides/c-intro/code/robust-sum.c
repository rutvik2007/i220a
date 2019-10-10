#include <stdio.h>
#include <stdlib.h>

//.1.
/** Output sum of integer command-line arguments on stdout. */
int
main(int argc, const char *argv[])
{
  int sum = 0;
  for (int i = 1; i < argc; i++) {
    char *p;
    int n = strtol(argv[i], &p, 10);
    if (*p == '\0') {
      sum += n;
    }
    //.2.
    else {
      fprintf(stderr,
              "bad argument %s not integer: ignored\n",
              argv[i]);
    }
  }
  printf("%d\n", sum);
  return 0;
}
