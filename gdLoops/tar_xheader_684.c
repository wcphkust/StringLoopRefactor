#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *p) {
  // tar-1.29/src/xheader.c:684:3
  for (; *p == ' ' || *p == '\t'; p++)
    continue;
  return p;
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
