#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *buf, char* q) {
  // tar-1.29/src/xheader.c:356:3
  while (q > buf && ISSLASH(q[-1]))
    q--;
  return q;
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
