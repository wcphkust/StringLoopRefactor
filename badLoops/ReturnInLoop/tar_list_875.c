#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop, too many values
char *loopFunction(char *str) {
  // tar-1.29/src/list.c:875:7
  for (;;) {
    value = (value << LG_256) + (unsigned char)*where++;
    if (where == lim)
      break;
    if (((value << LG_256 >> LG_256) | topbits) != value) {
      if (type && !silent)
        ERROR((0, 0, _("Archive base-256 value is out of %s range"), type));
      return -1;
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
