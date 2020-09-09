#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *p) {
  // wget-1.9/src/headers.c:203:3
  while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n')
    ++p;
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
