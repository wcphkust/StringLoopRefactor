#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *pattern) {
  // m4-1.4.18/src/builtin.c:1412:3

  int len = strlen(pattern);
  int i;
  for (i = 0; len > 0 && i < 6; i++)
    if (pattern[len - i - 1] != 'X')
      break;
  return pattern + i;
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
