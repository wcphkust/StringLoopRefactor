#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return value
char *loopFunction(char *str) {
  // git-2.18.0/xdiff/xutils.c:308:2
  for (; ptr < top && *ptr != '\n'; ptr++) {
    ha += (ha << 5);
    ha ^= (unsigned long)*ptr;
  }
}

void driver() {
  char str[N];
  klee_make_symbolic(str, sizeof(str), "str");

  char *p = loopFunction(str);
#ifdef DRIVER
#include "driver.c"
#endif
}

#ifdef MAIN_FUNC
#include "main.c"
#endif
