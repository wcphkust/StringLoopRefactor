#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop, too many variables
char *loopFunction(char *str) {
  // openssh-7.4p1/openbsd-compat/fmt_scaled.c:88:2
  while (*p == '-' || *p == '+') {
    if (*p == '-') {
      if (sign) {
        errno = EINVAL;
        return -1;
      }
      sign = -1;
      ++p;
    } else if (*p == '+') {
      if (sign) {
        errno = EINVAL;
        return -1;
      }
      sign = +1;
      ++p;
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
