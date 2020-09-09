#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop
char *loopFunction(char *str) {
  // bash-4.4/general.c:1029:3
  for (r = s; TILDE_END(*r) == 0; r++) {
    switch (*r) {
    case '\\':
    case '\'':
    case '"':
      return 0;
    }
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
