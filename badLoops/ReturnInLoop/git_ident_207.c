#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop
char *loopFunction(char *str) {
  // git-2.18.0/ident.c:207:2
  for (; *str; str++) {
    if (!crud(*str))
      return 1;
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
