#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *line) {
  int len = strlen(line);
  char* cp;
  // git-2.18.0/ident.c:310:2
  for (cp = line + len - 1; *cp != '>'; cp--)
    ;
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
