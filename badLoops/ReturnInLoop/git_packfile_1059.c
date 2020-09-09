#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop
char *loopFunction(char *str) {
  // git-2.18.0/packfile.c:1059:3
  while (c & 128) {
    base_offset += 1;
    if (!base_offset || MSB(base_offset, 7))
      return 0; /* overflow */
    c = base_info[used++];
    base_offset = (base_offset << 7) + (c & 127);
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
