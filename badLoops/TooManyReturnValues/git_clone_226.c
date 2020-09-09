#include <stdio.h>
#include <string.h>
#define N 10

//C: too many variables
char *loopFunction(char *str) {
  // git-2.18.0/builtin/clone.c:226:2

  for (ptr = start; ptr < end && !is_dir_sep(*ptr); ptr++) {
    if (*ptr == '@')
      start = ptr + 1;
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
