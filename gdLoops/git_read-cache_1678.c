#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *cp) {
  // git-2.18.0/read-cache.c:1678:2
  char *ep;
  for (ep = cp; *ep; ep++)
    ; /* find the end */
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
