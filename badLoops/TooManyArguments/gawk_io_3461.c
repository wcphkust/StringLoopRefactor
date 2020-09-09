#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *bp, char rs) {
  // gawk-4.2.0/io.c:3461:2
  while (*bp != rs)
    bp++;
  return bp;
}

void driver() {
  char str[N];
  klee_make_symbolic(str, sizeof(str), "str");

  char c;
  klee_make_symbolic(c, sizeof(c), "c");

  char *p = loopFunction(str, c);
#ifdef DRIVER
#include "driver.c"
#endif
}

#ifdef MAIN_FUNC
#include "main.c"
#endif
