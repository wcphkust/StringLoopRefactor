#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *host, char* port) {
  // libosip2-4.1.0/src/osipparser2/osip_uri.c:241:5
  while (host < port && *host != '[')
    host++;
}

void driver() {
  char str[N];
  klee_make_symbolic(str, sizeof(str), "str");

  char *p = loopFunction(str, str+N);
#ifdef DRIVER
#include "driver.c"
#endif
}

#ifdef MAIN_FUNC
#include "main.c"
#endif
