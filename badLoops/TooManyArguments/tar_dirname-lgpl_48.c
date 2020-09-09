#include <stdio.h>
#include <string.h>
#define N 10

//C: too complex dependent functions
# define ISSLASH(C) ((C) == '/' || (C) == '\\')
char *loopFunction(char *str) {
  // tar-1.29/gnu/dirname-lgpl.c:48:3
  for (length = last_component(file) - file; prefix_length < length; length--)
    if (!ISSLASH(file[length - 1]))
      break;
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
