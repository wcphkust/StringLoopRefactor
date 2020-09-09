#include <stdio.h>
#include <string.h>
#define N 10


//C: too many variables
char *loopFunction(char *str) {
  // diffutils-3.6/src/io.c:614:3
  while (p0 != buffer0 && (p0[-1] != '\n' || i--))
    p0--, p1--;
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
