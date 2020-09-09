#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *url, char* colon_ptr) {
  // git-2.18.0/urlmatch.c:224:2
  while (colon_ptr > url && *colon_ptr != ':' && *colon_ptr != ']')
    colon_ptr--;
  return colon_ptr;
}

void driver() {
  char str[N];
  klee_make_symbolic(str, sizeof(str), "str");

  char *p = loopFunction(str, str+N - 1);
#ifdef DRIVER
#include "driver.c"
#endif
}

#ifdef MAIN_FUNC
#include "main.c"
#endif
