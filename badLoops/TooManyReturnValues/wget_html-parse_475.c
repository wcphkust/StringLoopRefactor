#include <stdio.h>
#include <string.h>
#define N 10

//C: too many vairables
char *loopFunction(char *str) {
  // wget-1.9/src/html-parse.c:475:3
  while (state != AC_S_DONE && state != AC_S_BACKOUT) {
    if (p == end)
      state = AC_S_BACKOUT;
    switch (state) {
    case AC_S_DONE:
    case AC_S_BACKOUT:
      break;
    case AC_S_BANG:
      if (ch == '!') {
        ch = *p++;
        state = AC_S_DEFA

            ...
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
