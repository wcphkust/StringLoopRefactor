#include <stdio.h>
#include <string.h>
#define N 10

//C: side effects
char *loopFunction(char *str) {
  // make-4.2/variable.c:1681:9
  for (p = v->value; *p != '\0'; ++p) {
    if (*p == '$')
      putchar('$');
    putchar(*p);
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
