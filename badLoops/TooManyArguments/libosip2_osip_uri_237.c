#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *host, char* tmp) {
  // libosip2-4.1.0/src/osipparser2/osip_uri.c:237:3
  while (tmp > host && *tmp != ']')
    tmp--;

  return tmp;
}

void driver() {
  char str[N];
  klee_make_symbolic(str, sizeof(str), "str");

  char *p = loopFunction(str, str+N-1);
#ifdef DRIVER
#include "driver.c"
#endif
}

#ifdef MAIN_FUNC
#include "main.c"
#endif
