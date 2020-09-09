#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop
char *loopFunction(char *str) {
  // git-2.18.0/attr.c:203:2
  while (namelen--) {
    char ch = *name++;
    if (!(ch == '-' || ch == '.' || ch == '_' || ('0' <= ch && ch <= '9') ||
          ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')))
      return 0;
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
