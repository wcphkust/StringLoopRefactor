#include <stdio.h>
#include <string.h>
#define N 10

//C: multiple return values
char *loopFunction(char *str) {
  // git-2.18.0/sha1-name.c:783:3
  for (i = nth = 0; 0 <= nth && i < reflog_len; i++) {
    char ch = str[at + 2 + i];
    if ('0' <= ch && ch <= '9')
      nth = nth * 10 + ch - '0';
    else
      nth = -1;
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
