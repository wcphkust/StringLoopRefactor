#include <stdio.h>
#include <string.h>
#define N 10

//C: too many return values
char *loopFunction(char *str) {
  // openssh-7.4p1/ssh.c:416:2
  ndots = 0;
  for (cp = *hostp; *cp != '\0'; cp++) {
    if (*cp == '.')
      ndots++;
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
