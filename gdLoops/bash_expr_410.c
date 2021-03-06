#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

#define whitespace(c) (((c) == ' ') || ((c) == '\t'))
#define cr_whitespace(c) (whitespace(c) || ((c) == '\n'))
char *loopFunction(char *expr) {
  // bash-4.4/expr.c:410:3
  char *p;
  for (p = expr; p && *p && cr_whitespace(*p); p++)
    ;
  return p;
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
