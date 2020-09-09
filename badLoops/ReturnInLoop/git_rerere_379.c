#include <stdio.h>
#include <string.h>
#define N 10

//C: Return in loop
char *loopFunction(char *str) {
  // git-2.18.0/rerere.c:379:2
  while (marker_size--)
    if (*buf++ != marker_char)
      return 0;
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
