#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *buf, char* tail) {
  // git-2.18.0/commit.c:80:2
  while (buf < tail && *buf++ != '\n')
    /* nada */;

  return buf;
}

void driver() {
  char str[N];
  klee_make_symbolic(str, sizeof(str), "str");

  char *p = loopFunction(str, str+N);
#ifdef DRIVER
#include "driver.c"
#endif
}

#ifdef MAIN_FUNC
#include "main.c"
#endif
