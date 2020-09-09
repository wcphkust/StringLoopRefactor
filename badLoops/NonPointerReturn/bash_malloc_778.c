#include <stdio.h>
#include <string.h>
#define N 10

//C: not a string
char *loopFunction(char *str) {
  // bash-4.4/lib/malloc/malloc.c:778:3
  while (busy[nunits])
    nunits++;
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
