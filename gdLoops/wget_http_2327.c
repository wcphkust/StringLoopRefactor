#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *cp) {
  // wget-1.9/src/http.c:2327:7
  char *ep;
  for (ep = cp; *ep && *ep != '\"'; ep++)
    ;
  return ep;
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
