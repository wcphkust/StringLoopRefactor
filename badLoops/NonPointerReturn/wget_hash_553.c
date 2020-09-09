#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return type - hashing
char *loopFunction(char *str) {
  // wget-1.9/src/hash.c:553:5
  for (p += 1; *p != '\0'; p++)
    h = (h << 5) - h + *p;
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
