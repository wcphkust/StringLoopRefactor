#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop
char *loopFunction(char *s) {
  char ch;
  // git-2.18.0/pretty.c:215:2
  while ((ch = *s++) != '\0') {
    if (non_ascii(ch))
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
