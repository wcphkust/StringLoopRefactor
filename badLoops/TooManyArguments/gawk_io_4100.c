#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *cp, char *cpend) {
  // gawk-4.2.0/io.c:4100:2
  while (*cp != '/' && cp < cpend)
    cp++;
  return cp;
}

void driver() {
  char str[N];
  klee_make_symbolic(str, sizeof(str), "str");

  char *p = loopFunction(str, str+N);
#ifdef DRIVER
#include "driver.c"
#endif
}

#ifdef MAIN_FUNC
#include "main.c"
#endif
