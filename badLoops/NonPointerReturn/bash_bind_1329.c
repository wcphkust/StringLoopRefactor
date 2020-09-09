#include <stdio.h>
#include <string.h>
#define N 10

// C: many return values i, c
char *loopFunction(char *str) {
  // bash-4.4/lib/readline/bind.c:1329:3
  for (; (c = string[i]) && c != ':' && c != ' ' && c != '\t'; i++)
    ;
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
