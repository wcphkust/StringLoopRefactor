#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return, too many variables
char *loopFunction(char *str) {
  // diffutils-3.6/src/util.c:768:3
  for (s = str; *s; s++) {
    char c = *s;

    if (c == ' ') {
      must_quote = true;
      continue;
    }
    switch (c_escape_char(*s)) {
    case 1:
      plus += 3;
    /* fall through */
    case 0:
      break;
    default:
      plus++;
      break;
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
