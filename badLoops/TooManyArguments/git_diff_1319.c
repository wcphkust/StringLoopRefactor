#include <stdio.h>
#include <string.h>
#define N 10

//C: Too Many arguments
char *loopFunction(char *ep) {
  // git-2.18.0/diff.c:1319:2
  for (cp = ep; ep - line < len; ep++)
    if (*ep != ' ' && *ep != '\t')
      break;
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
