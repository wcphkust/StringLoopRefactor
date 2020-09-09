#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *str) {
  // patch-2.7/src/pch.c:387:3
  char *s;
  for (s = str; (*s >= '0' && *s <= '9') || (*s >= 'a' && *s <= 'f'); s++)
    /* do nothing */;
  return s;
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
