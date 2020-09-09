#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return type
char *loopFunction(char *str) {
  // bash-4.4/builtins/printf.def:866:2
  for (temp = 2 + (!evalue && !!sawc); ISOCTAL(*p) && temp--; p++)
    evalue = (evalue * 8) + OCTVALUE(*p);
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
