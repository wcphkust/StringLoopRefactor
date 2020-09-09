#include <stdio.h>
#include <string.h>
#define N 10

//C: too many return values
char *loopFunction(char *str) {
  // make-4.2/function.c:2456:3

  for (nargs = 1, end = beg; *end != '\0'; ++end)
    if (*end == ',')
      ++nargs;
    else if (*end == openparen)
      ++count;
    else if (*end == closeparen && --count < 0)
      break;
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
