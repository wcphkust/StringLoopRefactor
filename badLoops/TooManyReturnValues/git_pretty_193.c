#include <stdio.h>
#include <string.h>
#define N 10

//C: too many return values
char *loopFunction(char *msg) {
  // git-2.18.0/pretty.c:193:2
  for (;;) {
    char c = *msg++;
    if (!c)
      break;
    ret++;
    if (c == '\n')
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
