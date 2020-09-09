#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *hack) {
  // libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:89:5
  while (' ' == *(hack - 1)) /* get rid of extra spaces */
    hack--;
  return hack;
}

void driver() {
  char str[STR_SIZE];
  klee_make_symbolic(str, sizeof(str), "str");

  char *p = loopFunction(str);
#ifdef DRIVER
#include "driver.c"
#endif
}

#ifdef MAIN_FUNC
#include "main.c"
#endif
