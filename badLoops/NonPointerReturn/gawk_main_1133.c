#include <stdio.h>
#include <string.h>
#define N 10

//C: invalid return value
char *loopFunction(char *cp2) {
  // gawk-4.2.0/main.c:1133:3

  for (cp2 = arg + 1; *cp2; cp2++)
    if (!is_identchar((unsigned char)*cp2)) {
      badvar = true;
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
