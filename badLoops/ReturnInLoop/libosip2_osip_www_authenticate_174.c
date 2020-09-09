#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop
char *loopFunction(char *str) {
  // libosip2-4.1.0/src/src/osipparser2/osip_www_authenticate.c:174:3
  while ((' ' == *str) || ('\t' == *str) || (',' == *str))
    if (*str)
      str++;
    else
      return OSIP_SYNTAXERROR; /* bad header format */
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
