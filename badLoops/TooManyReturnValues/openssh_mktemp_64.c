#include <stdio.h>
#include <string.h>
#define N 10

//C: too many return values
char *loopFunction(char *str) {
  // openssh-7.4p1/openbsd-compat/mktemp.c:64:2
  for (start = ep; start > path && start[-1] == 'X'; start--) {
    if (tries < INT_MAX / NUM_CHARS)
      tries *= NUM_CHARS;
  }
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
