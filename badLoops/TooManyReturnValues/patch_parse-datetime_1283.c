#include <stdio.h>
#include <string.h>
#define N 10

//C: too many return values
char *loopFunction(char *str) {
  // patch-2.7/lib/parse-datetime.y:1283:3
  while ((*yyd++ = *yys++) != '\0')
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
