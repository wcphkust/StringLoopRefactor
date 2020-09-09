#include <stdio.h>
#include <string.h>
#define N 10

//C: too many return values
char *loopFunction(char *str) {
  // patch-2.7/src/pch.c:1140:3
  for (s = s0; ISDIGIT(*s); s++) {
    lin new_n = 10 * n + (*s - '0');
    overflow |= new_n / 10 != n;
    n = new_n;
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
