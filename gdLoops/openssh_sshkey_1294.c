#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *space) {
  // openssh-7.4p1/sshkey.c:1294:4
  while (*space == ' ' || *space == '\t')
    space++;
  return space;
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
