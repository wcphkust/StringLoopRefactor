#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return value
char *loopFunction(char *str) {
  // diffutils-3.6/src/context.c:155:3
  for (j = i; j < i + 40 && function[j] != '\n'; j++)
    continue;
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
