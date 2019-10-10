#include <stdio.h>

int //.1.
count_ones(unsigned v)
{
  int ones = 0;
  for (unsigned i = v; i > 0; i >>= 1) {
    if (i & 1) ones++;
  }
  return ones;
}

//.2.
int main() {
  unsigned values[] = { 123, 32, 255 };
  for (int i = 0; i < sizeof(values)/sizeof(values[0]);
       i++) {
    unsigned v = values[i];
    printf("# of ones in %u (0x%x) is %d\n",
           v, v, count_ones(v));
  }
  return 0;
}
