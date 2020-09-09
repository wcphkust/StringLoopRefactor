#include <stdio.h>
#include <string.h>
#define N 10

//C: sideeffect, goto
char *loopFunction(char *str) {
  // git-2.18.0/config.c:607:2
  do {
    if (c == '\n')
      goto error_incomplete_line;
    c = get_next_char();
  } while (isspace(c));
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
