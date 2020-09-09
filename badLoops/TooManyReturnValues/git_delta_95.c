#include <stdio.h>
#include <string.h>
#define N 10

//C: too many variables
char *loopFunction(char *str) {
  // git-2.18.0/delta.h:95:2
  do {
    cmd = *data++;
    size |= (cmd & 0x7f) << i;
    i += 7;
  } while (cmd & 0x80 && data < top);
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
