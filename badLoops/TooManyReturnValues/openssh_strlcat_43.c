#include <stdio.h>
#include <string.h>
#define N 10

//C: too many values
char *loopFunction(char *d) {
  // openssh-7.4p1/openbsd-compat/strlcat.c:43:2
  while (n-- != 0 && *d != '\0')
    d++;
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
