#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *value) {
  int len = strlen(value);
  // git-2.18.0/builtin/log.c:726:2
  while (len && value[len - 1] == '\n')
    len--;
  return value + len;
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
