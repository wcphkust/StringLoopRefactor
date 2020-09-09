#include <stdio.h>
#include <string.h>
#define N 10
//C: many return values
char *loopFunction(char *str) {
  // bash-4.4/lib/readline/bind.c:1258:3
  for (i = start, passc = 0; c = string[i]; i++) {
    if (passc) {
      passc = 0;
      if (c == 0)
        break;
      continue;
    }

    if (c == '\\') {
      passc = 1;
      continue;
    }

    if (c == delim)
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
