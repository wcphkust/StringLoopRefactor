#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return value, return in loop
char *loopFunction(char *str) {
  // diffutils-3.6/src/ifdef.c:410:2
  while ((c = *p++) != '\'') {
    unsigned int digit = c - '0';
    if (8 <= digit)
      return NULL;
    value = 8 * value + digit;
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
