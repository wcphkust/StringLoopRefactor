#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop, multiple values
char *loopFunction(char *str) {
  // bash-4.4/builtins/common.c:542:3
  while (*string && ISOCTAL(*string)) {
    digits++;
    result = (result * 8) + (*string++ - '0');
    if (result > 0777)
      return -1;
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
