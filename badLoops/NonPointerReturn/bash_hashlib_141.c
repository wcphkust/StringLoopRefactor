#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return value - hashing
char *loopFunction(char *str) {
  // bash-4.4/hashlib.c:141:3
  for (i = 0; *s; s++) {
    i *= 16777619;
    i ^= *s;
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
