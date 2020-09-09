#include <stdio.h>
#include <string.h>
#define N 10

//C: many return values
char *loopFunction(char *str) {
  // bash-4.4/bashline.c:4200:3
  for (passc = 0; c = string[i]; i++) {
    if (passc) {
      passc = 0;
      continue;
    }
    if (c == '\\') {
      passc++;
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
