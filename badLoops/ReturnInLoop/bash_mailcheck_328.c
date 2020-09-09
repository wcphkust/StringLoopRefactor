#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop
char *loopFunction(char *str) {
  // bash-4.4/mailcheck.c:328:3
  for (s = str, pass_next = 0; s && *s; s++) {
    if (pass_next) {
      pass_next = 0;
      continue;
    }
    if (*s == '\\') {
      pass_next++;
      continue;
    }
    if (*s == '?' || *s == '%')
      return s;
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
