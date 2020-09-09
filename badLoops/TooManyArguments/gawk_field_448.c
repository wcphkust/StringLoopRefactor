#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *scan, char* end) {
  // gawk-4.2.0/field.c:448:3
  while (scan < end && (*scan == ' ' || *scan == '\t' || *scan == '\n'))
    scan++;
  return scan;
}

void driver() {
  char str[N];
  klee_make_symbolic(str, sizeof(str), "str");

  char *p = loopFunction(str, str+N);
#ifdef DRIVER
#include "driver.c"
#endif
}

#ifdef MAIN_FUNC
#include "main.c"
#endif
