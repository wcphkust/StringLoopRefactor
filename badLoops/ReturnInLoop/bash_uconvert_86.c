#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop
char *loopFunction(char *str) {
  // bash-4.4/lib/sh/uconvert.c:86:3
  for (; p && *p; p++) {
    if (*p == DECIMAL) /* decimal point */
      break;
    if (DIGIT(*p) == 0)
      RETURN(0);
    ipart = (ipart * 10) + (*p - '0');
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
