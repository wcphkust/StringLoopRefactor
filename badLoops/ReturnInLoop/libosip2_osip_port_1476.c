#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop
char *loopFunction(char *str) {
  // libosip2-4.1.0/src/osipparser2/osip_port.c:1476:3
  while ((' ' == *pend) || ('\r' == *pend) || ('\n' == *pend) ||
         ('\t' == *pend)) {
    pend--;
    if (pend < pbeg) {
      *dst = '\0';
      return dst;
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
