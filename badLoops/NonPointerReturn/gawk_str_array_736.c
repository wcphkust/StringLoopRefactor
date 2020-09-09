#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return value - hashing
char *loopFunction(char *str) {
  // gawk-4.2.0/str_array.c:736:2
  while (len--) {
    hashVal += *str++;
    hashVal += (hashVal << 10);
    hashVal ^= (hashVal >> 6);
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
