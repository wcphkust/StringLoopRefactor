#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

#define whitespace(c) (((c) == ' ') || ((c) == '\t'))
#define cr_whitespace(c) (whitespace(c) || ((c) == '\n'))
char *loopFunction(char *cp) {
  // bash-4.4/expr.c:1240:3
  char c;
  while (cp && (c = *cp) && (cr_whitespace(c)))
    cp++;
  return cp;
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
