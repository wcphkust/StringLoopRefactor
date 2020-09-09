#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return values
char *loopFunction(char *str) {
  // git-2.18.0/diff.c:485:2
  while (0 < size--) {
    ch = *data++;
    if (ch == '\n') {
      count++;
      nl_just_seen = 1;
      completely_empty = 0;
    } else {
      nl_just_seen = 0;
      completely_empty = 0;
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
