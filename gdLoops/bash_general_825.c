#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *name) {
  // bash-4.4/general.c:825:5
  char *nbeg;
  for (nbeg = name; *nbeg; nbeg++)
    if (*nbeg == '/') {
      nbeg++;
      break;
    }

  return nbeg;
}

void driver() {
  char str[STR_SIZE];
  klee_make_symbolic(str, sizeof(str), "str");

  char *p = loopFunction(str);
#ifdef DRIVER
#include "driver.c"
#endif
}

#ifdef MAIN_FUNC
#include "main.c"
#endif
