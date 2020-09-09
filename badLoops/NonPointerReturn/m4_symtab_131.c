#include <stdio.h>
#include <string.h>
#define N 10

//C: invalid return value - hashing;
char *loopFunction(char *str) {
  // m4-1.4.18/src/symtab.c:131:3
  while ((ch = *ptr++) != '\0')
    val = (val << 7) + (val >> (sizeof(val) * CHAR_BIT - 7)) + ch;
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
