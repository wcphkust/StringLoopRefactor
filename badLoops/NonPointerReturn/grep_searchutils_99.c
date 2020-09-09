#include <stdio.h>
#include <string.h>
#define N 10

//C: many variables
char *loopFunction(char *str) {
  // grep-3.1/src/searchutils.c:99:9
  for (int i = 1; i <= 3; i++)
    if ((cur[-i] & 0xc0) != 0x80) {
      mbstate_t mbs = {0};
      size_t clen = mb_clen(cur - i, end - (cur - i), &mbs);
      if (i < clen && clen < (size_t)-2) {
        p0 = cur - i;
        p = p0 + clen;
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
