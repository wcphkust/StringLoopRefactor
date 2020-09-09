#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop
char *loopFunction(char *str) {
  // git-2.18.0/mailinfo.c:854:2
  while ((ch = *cp++)) {
    if (ch == ':')
      return 1;
    if ((33 <= ch && ch <= 57) || (59 <= ch && ch <= 126))
      continue;
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
