#include <stdio.h>
#include <string.h>
#define N 10

//C: too many return values
char *loopFunction(char *str) {
  // openssh-7.4p1/channels.c:1257:3
  for (found = 0, i = 2; i < nmethods + 2; i++) {
    if (p[i] == SSH_SOCKS5_NOAUTH) {
      found = 1;
      break;
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
