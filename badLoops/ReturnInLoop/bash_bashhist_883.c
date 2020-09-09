#include <stdio.h>
#include <string.h>
#define N 10

//C: has return in loop
char *loopFunction(char *str) {
  // bash-4.4/bashhist.c:883:3
  for (p = s; p && *p; p++) {
    if (*p == '\\')
      p++;
    else if (*p == '&')
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
