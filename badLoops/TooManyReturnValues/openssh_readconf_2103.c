#include <stdio.h>
#include <string.h>
#define N 10

//C: too many return values
char *loopFunction(char *str) {
  // openssh-7.4p1/readconf.c:2103:3
  /* find matching ']' */
  for (ep = cp + 1; *ep != ']' && *ep != '\0'; ep++) {
    if (*ep == '/')
      ispath = 1;
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
