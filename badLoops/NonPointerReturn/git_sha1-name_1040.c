#include <stdio.h>
#include <string.h>
#define N 10

//C: Multiple return values
char *loopFunction(char *str) {
  // git-2.18.0/sha1-name.c:1040:2
  for (cp = name + len - 1; name <= cp; cp--) {
    int ch = *cp;
    if ('0' <= ch && ch <= '9')
      continue;
    if (ch == '~' || ch == '^')
      has_suffix = ch;
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
