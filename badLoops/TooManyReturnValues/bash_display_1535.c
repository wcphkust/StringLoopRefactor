#include <stdio.h>
#include <string.h>
#define N 10

//C: too many variables
char *loopFunction(char *str) {
  // bash-4.4/lib/readline/display.c:1535:3
  for (od = ofd - old, oe = ofd; od < omax && *oe; oe++, od++)
    ;
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
