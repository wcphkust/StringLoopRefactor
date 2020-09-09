#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char* where0, char *lim) {
  // tar-1.29/src/list.c:907:4
  while (where0 != lim && !lim[-1])
    lim--;
 return lim;
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
