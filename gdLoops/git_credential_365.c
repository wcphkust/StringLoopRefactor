#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *slash) {
  // git-2.18.0/credential.c:365:2
  while (*slash == '/')
    slash++;

  return slash;
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
