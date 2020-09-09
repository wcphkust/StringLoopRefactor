#include <stdio.h>
#include <string.h>
#define N 10


//C: many return values
char *loopFunction(char *str) {
  // bash-4.4/general.c:834:3
  for (ndirs = 0, ntail = nbeg; *ntail; ntail++)
    if (*ntail == '/')
      ndirs++;
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
