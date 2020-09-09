#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *p) {
  int len = strlen(p);
  // git-2.18.0/sequencer.c:3450:4
  while (len && p[len - 1] != '\n')
    len--;
 
  return len + p;
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
