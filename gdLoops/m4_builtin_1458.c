#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *str) {
  // m4-1.4.18/src/builtin.c:1458:7

  int len = strlen(str);
  int i;
  for (i = len; i > 1; i--)
    if (str[i - 1] != 'X')
      break;
  return str + i;
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
