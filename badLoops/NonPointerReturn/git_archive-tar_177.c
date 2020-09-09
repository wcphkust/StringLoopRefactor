#include <stdio.h>
#include <string.h>
#define N 10

//C: invalid return type - checksum
char *loopFunction(char *str) {
  // git-2.18.0/archive-tar.c:177:2
  while (p < (const unsigned char *)header->chksum)
    chksum += *p++;
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
