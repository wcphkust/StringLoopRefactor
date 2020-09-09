#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return value
char *loopFunction(char *str) {
  // bash-4.4/subst.c:4494:4
  while (pp >= pat && *pp-- == '\\')
    unescaped_backslash = 1 - unescaped_backslash;
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
