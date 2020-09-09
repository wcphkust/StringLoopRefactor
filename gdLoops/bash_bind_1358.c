#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

#define whitespace(c) (((c) == ' ') || ((c) == '\t'))
char *loopFunction(char *value) {
  // bash-4.4/lib/readline/bind.c:1358:7
  while (*value && whitespace(*value))
    value++;
  return value;
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
