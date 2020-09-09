#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop
char *loopFunction(char *str) {
  // git-2.18.0/varint.c:9:2
  while (c & 128) {
    val += 1;
    if (!val || MSB(val, 7))
      return 0; /* overflow */
    c = *buf++;
    val = (val << 7) + (c & 127);
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
