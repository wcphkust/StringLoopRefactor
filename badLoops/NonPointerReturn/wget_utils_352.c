#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return value
char *loopFunction(char *str) {
  // wget-1.9/src/utils.c:352:3
  for (p = string; *p; p++)
    if (*p == chr)
      ++count;
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
