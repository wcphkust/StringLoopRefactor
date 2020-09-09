#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *line, char* out) {
  // make-4.2/misc.c:61:3
  while (out > line && out[-1] == '\\')
    --out;
  return out;
}

void driver() {
  char str[N];
  klee_make_symbolic(str, sizeof(str), "str");

  char *p = loopFunction(str, str+N);
#ifdef DRIVER
#include "driver.c"
#endif
}

#ifdef MAIN_FUNC
#include "main.c"
#endif
