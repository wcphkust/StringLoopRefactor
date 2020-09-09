#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return type
char *loopFunction(char *str) {
  // diffutils-3.6/src/context.c:157:3
  while (i < j && c_isspace((unsigned char)function[j - 1]))
    j--;
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
