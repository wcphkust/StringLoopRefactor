#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *s) {
  // wget-1.9/src/utils.c:712:3

  int l = strlen(s);
  while (l && s[l] != '/')
    --l;
  return s + l;
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
