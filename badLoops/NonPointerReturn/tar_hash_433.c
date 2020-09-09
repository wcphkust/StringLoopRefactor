#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return type - hashing
char *loopFunction(char *str) {
  // tar-1.29/gnu/hash.c:433:3
  for (; (ch = *string); string++)
    value = (value * 31 + ch) % n_buckets;
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
