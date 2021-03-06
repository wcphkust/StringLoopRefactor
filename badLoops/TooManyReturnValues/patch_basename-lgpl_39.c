#include <stdio.h>
#include <string.h>
#define N 10

//C: too many values
char *loopFunction(char *str) {
  // patch-2.7/lib/basename-lgpl.c:39:3
  for (p = base; *p; p++) {
    if (ISSLASH(*p))
      saw_slash = true;
    else if (saw_slash) {
      base = p;
      saw_slash = false;
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
