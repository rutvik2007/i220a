#include <stdio.h>

/** Ref: <http://en.wikipedia.org/wiki/Kibibyte> */

//.1.
/** Package unit-name and its abbreviation. */
typedef struct {
  const char *name;
  const char *abbr;
} Unit;
//.2.
static Unit metricUnits[] = {
  { "kilobyte", "kB" },
  { "megabyte", "MB" },
  { "gigabyte", "GB" },
  { "terabyte", "TB" },
  { "petabyte", "PB" },
  { "exabyte", "EB" },
  { "zettabyte", "ZB" },
  { "yottabyte", "YB" },
};
//.3.
static Unit iecUnits[] = {
  { "kibibyte", "KiB" },
  { "mebibyte", "MiB" },
  { "gibibyte", "GiB" },
  { "tebibyte", "TiB" },
  { "pebibyte", "PiB" },
  { "exbibyte", "EiB" },
  { "zebibyte", "ZiB" },
  { "yobibyte", "YiB" },
};
//.4.
static void
outUnits(unsigned base, Unit units[], int nUnits,
         FILE *out)
{
  unsigned long long v = 1;
  for (int i = 0; i < nUnits; i++) {
    v *= base;
    fprintf(out, "%d**%d = 1 %s (%s) "
            "which is %llu bytes\n",
            base, i + 1, units[i].name,
            units[i].abbr, v);
  }
  fprintf(out, "\n");
}
//.5.
int
main()
{
  outUnits(1000u, metricUnits,
           sizeof(metricUnits)/sizeof(metricUnits[0]),
           stdout);
  outUnits(1024u, iecUnits,
           sizeof(iecUnits)/sizeof(iecUnits[0]),
           stdout);
  return 0;
}
