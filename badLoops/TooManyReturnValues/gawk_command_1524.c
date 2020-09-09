#include <stdio.h>
#include <string.h>
#define N 10

//C: too many variables
char *loopFunction(char *p) {
  // gawk-4.2.0/command.y:1524:3
  for (i++, q = p + 1; i < len; i++, q++)
    if (*q == ' ' || *q == '\t')
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
