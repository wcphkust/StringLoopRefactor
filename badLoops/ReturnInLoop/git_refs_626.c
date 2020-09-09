#include <stdio.h>
#include <string.h>
#define N 10

//C: Return in loop
char *loopFunction(char *str) {
  // git-2.18.0/refs.c:626:2
  for (c = refname; *c; c++) {
    if (!isupper(*c) && *c != '-' && *c != '_')
      return 0;
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
