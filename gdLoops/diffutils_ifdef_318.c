#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

#  define IN_CTYPE_DOMAIN(c) 1
#define ISDIGIT(c) (IN_CTYPE_DOMAIN (c) && isdigit ((unsigned char)c))
char *loopFunction(char *f) {
  // diffutils-3.6/src/ifdef.c:318:3
  char c = *f++;
  while (ISDIGIT(c))
    c = *f++;
  return f;
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
