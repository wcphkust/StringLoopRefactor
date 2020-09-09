#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return type
char *loopFunction(char *str) {
  // tar-1.29/src/create.c:991:3
  for (i = sizeof *header; i-- != 0;)
    /* We can't use unsigned char here because of old compilers, e.g. V7.  */
    sum += 0xFF & *p++;
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
