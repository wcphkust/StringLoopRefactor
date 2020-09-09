#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop
char *loopFunction(char *str) {
  // git-2.18.0/path.c:1264:2
  while (1) {
    char ch = *p++;
    if (sl) {
      if (ch == '.')
        ndot++;
      else if (ch == '/') {
        if (ndot < 3)
          /* reject //, /./ and /../ */
          return -1;
        ndot = 0;
      } else if (ch == 0) {
        if (0 < ndot && ndot < 3)
          /* reject /.$ and /..$ */
          return -1;
        return 0;
      } else
        sl = ndot = 0;
    } else if (ch == 0)
      return 0;
    else if (ch == '/') {
      sl = 1;
      ndot = 0;
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
