#include <stdio.h>
#include <string.h>
#define N 10


//C: two return values
char *loopFunction(char *str) {
  // bash-4.4/lib/readline/histexpand.c:342:3
  for (p = s; p && *p; p++, len++) {
    if (*p == '\'')
      len += 3;
    else if (whitespace(*p) || *p == '\n')
      len += 2;
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
