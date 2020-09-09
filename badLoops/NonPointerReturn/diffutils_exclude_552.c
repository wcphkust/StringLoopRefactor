#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return type
char *loopFunction(char *str) {
  // diffutils-3.6/lib/exclude.c:552:8
  while (len > 0 && ISSLASH(pattern[len - 1]))
    --len;
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
