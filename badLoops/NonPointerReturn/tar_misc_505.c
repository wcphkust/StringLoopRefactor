#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return types
char *loopFunction(char *str) {
  // tar-1.29/src/misc.c:505:4
  while (ISDIGIT(*++p))
    if (digits < LOG10_BILLION)
      digits++, ns = 10 * ns + (*p - '0');
    else
      trailing_nonzero |= *p != '0';
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
