#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *status) {
  // tar-1.29/lib/rtapelib.c:243:7
  for (; *status == ' ' || *status == '\t'; status++)
    continue;
  return status;
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
