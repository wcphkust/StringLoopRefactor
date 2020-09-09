#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *line) {
  // make-4.2/read.c:1797:11
  char termin = *line == '(' ? ',' : *line;
  while (*line != '\0' && *line != termin)
    ++line;
  return line;
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
