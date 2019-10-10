#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

//.1.
enum { COUNT_CHARS = 7 };

static int nCTotal = 0;         /* total # of chars */
static int nWTotal = 0;         /* total # of words */
static int nLTotal = 0;         /* total # of lines */

void //.2.
wc(const char *fName, FILE *f)
{
  int inWord = 0;
  int nC = 0, nW = 0, nL = 0;
  int c;
  //standard C idiom for reading file while checking EOF
  while ((c = fgetc(f)) != EOF) {
    nC++;
    if (c == '\n') nL++;
    if (isspace(c)) {
      inWord = 0;
    }
    //.3.
    else {
      if (!inWord) nW++;
      inWord = 1;
    }
  }
  if (ferror(f)) {
    fprintf(stderr, "i/o error: %s\n",
            strerror(errno));
  }
  printf("%*d %*d %*d %s\n", COUNT_CHARS, nL,
         COUNT_CHARS, nW, COUNT_CHARS, nC, fName);
  nCTotal += nC; nWTotal += nW; nLTotal += nL;
}

int //.4.
main(int argc, const char *argv[])
{
  int i;
  if (argc == 1) {
    wc("", stdin);
  }
  else {
    for (i = 1; i < argc; i++) {
      FILE *in = fopen(argv[i], "r");
      if (!in) {
        fprintf(stderr, "could not read %s: %s\n",
                argv[i], strerror(errno));
      }
      //.5.
      else {
        wc(argv[i], in);
        fclose(in);
      }
    } //for (i = 1; i < argc; i++)
    if (argc > 2) {
      printf("%*d %*d %*d total\n",
             COUNT_CHARS, nLTotal, COUNT_CHARS,
             nWTotal, COUNT_CHARS, nCTotal);
    }
  } //else if argc != 1
  return 0;
}
