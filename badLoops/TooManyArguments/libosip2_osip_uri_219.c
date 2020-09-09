#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char* host, char *port) {
  // libosip2-4.1.0/src/osipparser2/osip_uri.c:219:3
  while (port > host && *port != ']' && *port != ':')
    port--;
  return port;
}

void driver() {
  char str[N];
  klee_make_symbolic(str, sizeof(str), "str");

  char *p = loopFunction(str, str+N -1);
#ifdef DRIVER
#include "driver.c"
#endif
}

#ifdef MAIN_FUNC
#include "main.c"
#endif
