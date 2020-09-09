#include <stdio.h>
#include <string.h>
#define N 10

//C: unclear return
char *loopFunction(char *str) {
  // git-2.18.0/ident.c:291:2
  for (cp = split->mail_begin; cp < line + len; cp++)
    if (*cp == '>') {
      split->mail_end = cp;
      break;
    }
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
