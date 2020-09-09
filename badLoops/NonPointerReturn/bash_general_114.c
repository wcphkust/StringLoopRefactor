#include <stdio.h>
#include <string.h>
#define N 10

//C: non pointer return value
char *loopFunction(char *str) {
  // bash-4.4/general.c:114:3
  for (; s && *s && DIGIT(*s); s++)
    ret = (ret * 10) + TODIGIT(*s);
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
