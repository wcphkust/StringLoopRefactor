#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop
char *loopFunction(char *str) {
  // gawk-4.2.0/mpfr.c:236:2
  for (; *s != '\0'; s++) {
    if (*s == dec_point || *s == 'e' || *s == 'E')
      return true;
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
