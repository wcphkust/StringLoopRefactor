#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return value hashing
char *loopFunction(char *str) {
  // git-2.18.0/ewah/ewah_bitmap.c:705:2
  while (size--)
    crc = (crc << 5) - crc + (uint32_t)*p++;
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
