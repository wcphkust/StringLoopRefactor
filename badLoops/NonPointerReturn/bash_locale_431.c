#include <stdio.h>
#include <string.h>
#define N 10


//C: two return values
char *loopFunction(char *str) {
  // bash-4.4/locale.c:431:3
  for (len = 0, s = string; s && *s; s++) {
    len++;
    if (*s == '"' || *s == '\\')
      len++;
    else if (*s == '\n')
      len += 5;
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
