#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop
char *loopFunction(char *str) {
  // gawk-4.2.0/io.c:4082:2

  while (*cp != '/') {
    if (++cp >= cpend)
      return false;
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
