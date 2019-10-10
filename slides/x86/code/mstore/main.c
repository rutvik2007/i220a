#include <stdio.h>

void multStore(long, long, long *);

int main() {
  long d;
  multStore(2, 3, &d);
  printf("2 * 3 --> %ld\n", d);
  return 0;
}

//.1.
long mult2(long a, long b) {
  long s = a * b;
  return s;
}
