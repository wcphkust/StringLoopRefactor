#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *bob, char* scan) {
  // git-2.18.0/refs/files-backend.c:1893:2
  while (bob < scan && *(--scan) != '\n')
    ; /* keep scanning backwards */

  return scan;
}

void driver() {
  char str[N];
  klee_make_symbolic(str, sizeof(str), "str");

  char *p = loopFunction(str, str + N + 1);
#ifdef DRIVER
#include "driver.c"
#endif
}

#ifdef MAIN_FUNC
#include "main.c"
#endif
