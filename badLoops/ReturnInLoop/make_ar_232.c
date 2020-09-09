#include <stdio.h>
#include <string.h>
#define N 10

//C: many variables, return in loop
char *loopFunction(char *str) {
  // make-4.2/ar.c:232:3
  for (p = pattern; *p != '\0'; ++p)
    switch (*p) {
    case '?':
    case '*':
      return 1;

    case '\\':
      if (quote)
        ++p;
      break;

    case '[':
      opened = 1;
      break;

    case ']':
      if (opened)
        return 1;
      break;
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
