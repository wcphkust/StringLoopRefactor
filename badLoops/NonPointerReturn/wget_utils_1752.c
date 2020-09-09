#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return value
char *loopFunction(char *str) {
  // wget-1.9/src/utils.c:1752:3
  for (i = 0; *s; s++, i++) {
    if (*s == '&')
      i += 4; /* `amp;' */
    else if (*s == '<' || *s == '>')
      i += 3; /* `lt;' and `gt;' */
    else if (*s == '\"')
      i += 5; /* `quot;' */
    else if (*s == ' ')
      i += 4; /* #32; */
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
