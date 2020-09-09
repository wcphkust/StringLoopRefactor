#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return value
char *loopFunction(char *str) {
  // git-2.18.0/sha1-file.c:1149:3
  for (;;) {
    unsigned long c = *hdr - '0';
    if (c > 9)
      break;
    hdr++;
    size = size * 10 + c;
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
