#include <limits.h>
#include <stdio.h>

//.1.
static void out_bits(short value, FILE *out)
{
  fprintf(out, "%d == 0x%x == 0%o == 0b",
          value, value, value);
  int nBits = CHAR_BIT * sizeof(value);
  unsigned mask = 0x1 << (nBits - 1);
  for (int i = 0; i < nBits; i++) {
    char c = (mask & value) ? '1' : '0';
    mask >>= 1;
    fprintf(out, "%c", c);
    if (i % 4 == 3 && i != nBits - 1) fprintf(out, "_");
  }
  fprintf(out, "\n");
}

//.2.
int main()
{
  short values[] = {
    0, 16, 255, 1<<(sizeof(short)*CHAR_BIT - 2), -1
  };
  for (int i = 0;
       i < sizeof(values)/sizeof(values[0]);
       i++) {
    out_bits(values[i], stdout);
  }
  return 0;
}
