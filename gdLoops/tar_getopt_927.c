#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *nameend) {
  // tar-1.29/gnu/getopt.c:927:9
  for (; *nameend && *nameend != '=';
       nameend++)
    /* Do nothing.  */;
  return nameend;
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
