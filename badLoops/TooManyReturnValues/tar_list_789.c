#include <stdio.h>
#include <string.h>
#define N 10

//C: too many values
char *loopFunction(char *str) {
  // tar-1.29/src/list.c:789:4
  for (;;) {
    value += 7 - digit;
    where++;
    if (where == lim || !ISODIGIT(*where))
      break;
    digit = *where - '0';
    overflow |= value != (value << LG_8 >> LG_8);
    value <<= LG_8;
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
