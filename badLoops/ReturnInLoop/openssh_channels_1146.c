#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop
char *loopFunction(char *str) {
  // openssh-7.4p1/channels.c:1146:2
  for (found = 0, i = len; i < have; i++) {
    if (p[i] == '\0') {
      found++;
      if (found == need)
        break;
    }
    if (i > 1024) {
      /* the peer is probably sending garbage */
      debug("channel %d: decode socks4: too long", c->self);
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
