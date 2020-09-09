#include <stdio.h>
#include <string.h>
#define N 10

//C: too many variables
char *loopFunction(char *str) {
  // openssh-7.4p1/openbsd-compat/blowfish.c:413:2
  for (i = 0; i < 4; i++, j++) {
    if (j >= databytes)
      j = 0;
    temp = (temp << 8) | data[j];
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
