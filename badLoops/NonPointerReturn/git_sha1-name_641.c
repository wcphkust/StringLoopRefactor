#include <stdio.h>
#include <string.h>
#define N 10

//C: multiple return values
char *loopFunction(char *str) {
  // git-2.18.0/sha1-name.c:641:2
  for (cnt = 0; cnt < len; cnt++) {
    switch (*path++) {
    case '\0':
      break;
    case '/':
      if (slash)
        break;
      slash = 1;
      continue;
    case '.':
      continue;
    default:
      slash = 0;
      continue;
    }
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
