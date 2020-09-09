#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop
char *loopFunction(char *str) {
  // git-2.18.0/apply.c:1142:2
  for (i = 0; i < llen; i++) {
    int ch = line[i];
    if (ch == '/' && --nslash <= 0)
      return (i == 0) ? NULL : &line[i + 1];
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
