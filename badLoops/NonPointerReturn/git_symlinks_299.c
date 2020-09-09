#include <stdio.h>
#include <string.h>
#define N 10

//C: multiple return values
char *loopFunction(char *str) {
  // git-2.18.0/symlinks.c:299:2
  /* Find last slash inside 'name' */
  while (i < len) {
    if (name[i] == '/')
      last_slash = i;
    i++;
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
