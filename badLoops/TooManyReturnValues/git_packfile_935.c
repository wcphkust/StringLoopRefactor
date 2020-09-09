#include <stdio.h>
#include <string.h>
#define N 10

//C: too many return values
char *loopFunction(char *str) {
  // git-2.18.0/packfile.c:935:2
  while (c & 0x80) {
    if (len <= used || bitsizeof(long) <= shift) {
      error("bad object header");
      size = used = 0;
      break;
    }
    c = buf[used++];
    size += (c & 0x7f) << shift;
    shift += 7;
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
