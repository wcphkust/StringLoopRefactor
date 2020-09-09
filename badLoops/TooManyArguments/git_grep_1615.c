#include <stdio.h>
#include <string.h>
#define N 10

//C: Unclear arguments
char *loopFunction(char *str) {
  // git-2.18.0/grep.c:1615:2
  for (sp = bol + earliest; bol < sp && sp[-1] != '\n'; sp--)
    ; /* find the beginning of the line */
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
