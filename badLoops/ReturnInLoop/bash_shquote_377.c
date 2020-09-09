#include <stdio.h>
#include <string.h>
#define N 10


//C: return in loop
char *loopFunction(char *str) {
  // bash-4.4/lib/sh/shquote.c:377:3
  for (s = string; s && *s; s++) {
    if (*s == '\'' || *s == '"' || *s == '\\')
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
