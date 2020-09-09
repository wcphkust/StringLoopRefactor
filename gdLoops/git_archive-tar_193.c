#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *path) {
  // git-2.18.0/archive-tar.c:193:2
  klee_assume(path[0] != '\0');
  int i = strlen(path);
  do {
    i--;
  } while (i > 0 && path[i] != '/');
  return path + i;
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
