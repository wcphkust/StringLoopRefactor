#include <stdio.h>
#include <string.h>
#define N 10

//C: too complex inputs
char *loopFunction(char *str) {
  // git-2.18.0/xdiff-interface.c:121:2
  while (recovered < trimmed)
    if (ap[recovered++] == '\n')
      break;
}

void driver() {
  char str[N];
  klee_make_symbolic(str, sizeof(str), "str");

  char *p = loopFunction(str);
#ifdef DRIVER
#include "driver.c"
#endif
}

#ifdef MAIN_FUNC
#include "main.c"
#endif
