#include <stdio.h>
#include <string.h>
#define N 10

//C: Return in loop
char *loopFunction(char *str) {
  // gawk-4.2.0/int_array.c:104:2
  while (++s < end) {
    if (*s < '0' || *s > '9')
      return false;
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
