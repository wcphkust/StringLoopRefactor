#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop
char *loopFunction(char *str) {
  // make-4.2/misc.c:309:3
  while (s < limit)
    if (*s++ == c)
      return (char *)(s - 1);
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
