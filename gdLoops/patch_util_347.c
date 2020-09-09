#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

# define ISSLASH(C) ((C) == '/' || (C) == '\\')
char *loopFunction(char *t) {
  // patch-2.7/src/util.c:347:4
  char *o;
  int tlen = strlen(t);
  int olen;
  for (o = t + tlen, olen = 0; o > t && !ISSLASH(*(o - 1)); o--)
    /* do nothing */;
  return o;
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
