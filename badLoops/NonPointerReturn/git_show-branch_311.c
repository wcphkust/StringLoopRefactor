#include <stdio.h>
#include <string.h>
#define N 10

//C: multiple return values
char *loopFunction(char *str) {
  // git-2.18.0/builtin/show-branch.c:311:2
  for (p = s, ver = 0; '0' <= (ch = *p) && ch <= '9'; p++)
    ver = ver * 10 + ch - '0';
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
