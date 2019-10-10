#include <stdio.h>

static int acc = 123;
int main()
{
  int values[] = { 2, 5, -9, };
  for (int i = 0; i < sizeof(values)/sizeof(values[0]);
       i++) {
    int value = values[i];
    acc += value;
  }
  printf("%d\n", acc);
  return 0;
}
