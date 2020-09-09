#include <stdio.h>
#include <string.h>
#define N 10

//C: Return in loop
char *loopFunction(char *str) {
  // git-2.18.0/remote.c:479:2
  while (*name)
    if (is_dir_sep(*name++))
      return 0;
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
