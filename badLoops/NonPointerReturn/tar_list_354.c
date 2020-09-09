#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return type
char *loopFunction(char *str) {
  // tar-1.29/src/list.c:354:3
  for (i = sizeof *header; i-- != 0;) {
    unsigned_sum += (unsigned char)*p;
    signed_sum += (signed char)(*p++);
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
