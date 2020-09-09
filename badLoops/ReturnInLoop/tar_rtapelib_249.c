#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop, too many values
char *loopFunction(char *str) {
  // tar-1.29/lib/rtapelib.c:249:7
  for (;;) {
    int digit = *status++ - '0';
    if (9 < (unsigned)digit)
      break;
    else {
      off_t c10 = 10 * count;
      off_t nc = negative ? c10 - digit : c10 + digit;
      if (c10 / 10 != count || (negative ? c10 < nc : nc < c10))
        return -1;
      count = nc;
    }
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
