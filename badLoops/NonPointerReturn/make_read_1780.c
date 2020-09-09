#include <stdio.h>
#include <string.h>
#define N 10

//C: many return values
char *loopFunction(char *str) {
  // make-4.2/read.c:1780:11
  for (line = s2; *line != '\0'; ++line) {
    if (*line == '(')
      ++count;
    else if (*line == ')') {
      if (count <= 0)
        break;
      else
        --count;
    }
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
