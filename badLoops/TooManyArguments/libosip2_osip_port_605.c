#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *sep, char end_separator) {
  // libosip2-4.1.0/src/osipparser2/osip_port.c:605:3
  while ((*sep != end_separator) && (*sep != '\0') && (*sep != '\r') &&
         (*sep != '\n'))
    sep++;
  return sep;
}

void driver() {
  char str[N];
  klee_make_symbolic(str, sizeof(str), "str");

  char end_sep;
  klee_make_symbolic(&end_sep, sizeof(end_sep), "end_sep");

  char *p = loopFunction(str, end_sep);
#ifdef DRIVER
#include "driver.c"
#endif
}

#ifdef MAIN_FUNC
#include "main.c"
#endif
