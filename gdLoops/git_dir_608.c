#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *p) {
  int i;
  int len = strlen(p);
  // git-2.18.0/dir.c:608:2
  for (i = 0; i < len; i++) {
    if (p[i] == '/')
      break;
  }
  return p + i;
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
