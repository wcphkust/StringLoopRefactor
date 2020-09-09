#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *s) {
  // bash-4.4/shell.c:1948:7
  while (*++s == '-')
    ;
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
