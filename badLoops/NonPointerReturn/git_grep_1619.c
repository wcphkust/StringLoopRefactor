#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return value
char *loopFunction(char *str) {
  // git-2.18.0/grep.c:1619:2
  for (sp = bol; sp < last_bol; sp++) {
    if (*sp == '\n')
      lno++;
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
