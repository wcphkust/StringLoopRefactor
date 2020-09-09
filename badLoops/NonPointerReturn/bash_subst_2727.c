#include <stdio.h>
#include <string.h>
#define N 10


//C: bad return type
char *loopFunction(char *str) {
  // bash-4.4/subst.c:2727:3
  for (xflags = 0, s = ifs_value; s && *s; s++) {
    if (*s == CTLESC)
      xflags |= SX_NOCTLESC;
    else if (*s == CTLNUL)
      xflags |= SX_NOESCCTLNUL;
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
