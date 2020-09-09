#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop, too many return values
char *loopFunction(char *str) {
  // wget-1.9/src/convert.c:538:3
  for (; beg < end; beg++) {
    switch (*beg) {
    case '&':
      saw_amp = 1;
      break;
    case '#':
      if (!saw_amp) {
        *bp = beg;
        *ep = end;
        return 1;
      }
    /* fallthrough */
    default:
      saw_amp = 0;
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
