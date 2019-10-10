#include <stdio.h>

int sum(int a, int b, int c) {
  int s = a + b + c;
  printf("%d + %d + %d = %d\n", a, b, c, s);
  return s;
}

int
main()
{
  int s = sum(22, 33, 44);
  return 0;
}
