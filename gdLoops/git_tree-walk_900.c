#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *match) {
  // git-2.18.0/tree-walk.c:900:3
  int dirlen, matchlen = strlen(match);
  dirlen = matchlen;
  while (dirlen && match[dirlen - 1] != '/')
    dirlen--;

  return match + dirlen;
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
