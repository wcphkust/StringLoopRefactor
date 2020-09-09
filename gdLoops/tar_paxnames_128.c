#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

#define ISSLASH(C) ((C) == '/' || (C) == '\\')
char *loopFunction(char *p) {
  // tar-1.29/lib/paxnames.c:128:7
  for (; ISSLASH(*p); p++)
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
