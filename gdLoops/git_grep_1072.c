#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *cp) {
  int l = strlen(cp);
  // git-2.18.0/grep.c:1072:2
  while (l && *cp != '\n') {
    l--;
    cp++;
  }
  return cp;
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
