#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return type
char *loopFunction(char *str) {
  // tar-1.29/gnu/modechange.c:169:5
  for (p = mode_string; *p; p++)
    needed += (*p == '=' || *p == '+' || *p == '-');
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
