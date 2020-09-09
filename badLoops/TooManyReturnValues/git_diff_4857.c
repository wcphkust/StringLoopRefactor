#include <stdio.h>
#include <string.h>
#define N 10

//C: too many return values
char *loopFunction(char *str) {
  // git-2.18.0/diff.c:4857:2
  for (;;) {
    ch = *cp;
    if (!dot && ch == '.') {
      scale = 1;
      dot = 1;
    } else if (ch == '%') {
      scale = dot ? scale * 100 : 100;
      cp++; /* % is always at the end */
      break;
    } else if (ch >= '0' && ch <= '9') {
      if (scale < 100000) {
        scale *= 10;
        num = (num * 10) + (ch - '0');
      }
    } else {
      break;
    }
    cp++;
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
