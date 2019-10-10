#include <stdio.h>
#include <stdlib.h>

//.1.
/** Sum numeric strings [*start, *end), silently ignoring
 *  any strings which are not valid C integer literals.
 */
long
ptr_sum(const char **start, const char **end)
{
  long sum = 0;
  for (const char **p = start; p != end; p++) {
    char *endP;
    long v = strtol(*p, &endP, 0);//0: c-syntax ints
    if (*endP == '\0') sum += v;
  }
  return sum;
}
//.2.
int
main(int argc, const char *argv[])
{
  printf("%ld\n", ptr_sum(&argv[1], &argv[argc]));
  return 0;
}
