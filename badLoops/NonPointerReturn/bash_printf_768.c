#include <stdio.h>
#include <string.h>
#define N 10

//C:  bad return type
char *loopFunction(char *str) {
  // bash-4.4/builtins/printf.def:768:4
  while (DIGIT(*fmt))
    mpr = (mpr * 10) + (*fmt++ - '0');
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
