#include <stdio.h>
#include <string.h>
#define N 10

//C: too many variables
char *loopFunction(char *str) {
  // wget-1.9/src/ftp-basic.c:208:9
  for (cp = respline + strlen(skey_head[i]); '0' <= *cp && *cp <= '9'; cp++) {
    skey_sequence = skey_sequence * 10 + *cp - '0';
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
