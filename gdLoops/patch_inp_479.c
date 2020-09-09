#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *q) {
  // patch-2.7/src/inp.c:479:6
  for (; *q++ != '\n';)
    /* do nothing */;
  return q;
}

void driver() {
  char str[STR_SIZE];
  klee_make_symbolic(str, sizeof(str), "str");

  char *p = loopFunction(str);
#ifdef DRIVER
#include "driver.c"
#endif
}

#ifdef MAIN_FUNC
#include "main.c"
#endif
