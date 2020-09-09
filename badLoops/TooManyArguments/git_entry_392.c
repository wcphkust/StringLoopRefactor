#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *path, char* slash) {
  // git-2.18.0/entry.c:392:2
  while (path < slash && *slash != '/')
    slash--;

  return slash;
}

void driver() {
  char str[N];
  klee_make_symbolic(str, sizeof(str), "str");

  char *p = loopFunction(str, str+N -1);
#ifdef DRIVER
#include "driver.c"
#endif
}

#ifdef MAIN_FUNC
#include "main.c"
#endif
