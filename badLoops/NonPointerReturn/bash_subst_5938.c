#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return value
char *loopFunction(char *str) {
  // bash-4.4/subst.c:5938:3
  for (skip_ctlesc = skip_ctlnul = 0, s = ifs_value; s && *s; s++)
    skip_ctlesc |= *s == CTLESC, skip_ctlnul |= *s == CTLNUL;
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
