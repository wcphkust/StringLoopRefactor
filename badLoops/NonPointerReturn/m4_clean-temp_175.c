#include <stdio.h>
#include <string.h>
#define N 10

//C: invalid return type
char *loopFunction(char *str) {
  // m4-1.4.18/src/clean-temp.c:175:3
  for (; *s; s++)
    h = *s + ((h << 9) | (h >> (SIZE_BITS - 9)));
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
