#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *s, char *end) {
  // openssh-7.4p1/sshbuf-getput-basic.c:413:2
  /* Skip leading zero bytes */
  int len = end - s; //Can't use strlen here because trivially true
  for (; len > 0 && *s == 0; len--, s++)
    ;
  return s;
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
