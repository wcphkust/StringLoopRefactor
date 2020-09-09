#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *candidates) {
  char *p;
  // git-2.18.0/builtin/commit.c:628:2
  for (p = candidates; *p == ' '; p++)
    ;

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
