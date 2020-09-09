#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

#define whitespace(c) (((c) == ' ') || ((c) == '\t'))
char *loopFunction(char *value) {
  // bash-4.4/lib/readline/bind.c:1366:4
  char *e = value + strlen(value) - 1;
  while (e >= value && whitespace(*e))
    e--;
  return e;
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
