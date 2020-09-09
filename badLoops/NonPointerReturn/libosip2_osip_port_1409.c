#include <stdio.h>
#include <string.h>
#define N 10

//C: invalid loop value - hashing
char *loopFunction(char *str) {
  // libosip2-4.1.0/src/osipparser2/osip_port.c:1409:3
  while ((c = *str++))
    hash = ((hash << 5) + hash) + c;
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
