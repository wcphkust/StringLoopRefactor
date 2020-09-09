#include <stdio.h>
#include <string.h>
#define N 10

//C: too many return values
char *loopFunction(char *str) {
  // patch-2.7/src/pch.c:331:4
  for (s = str, mode = 0; s < str + 6; s++) {
    if (*s >= '0' && *s <= '7')
      mode = (mode << 3) + (*s - '0');
    else {
      mode = 0;
      break;
    }
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
