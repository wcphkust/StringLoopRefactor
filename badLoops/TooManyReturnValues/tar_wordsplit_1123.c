#include <stdio.h>
#include <string.h>
#define N 10

//C: too many variables
char *loopFunction(char *str) {
  // tar-1.29/lib/wordsplit.c:1123:8
  for (j = i + 1; j < len && command[j] != '\n'; j++)
    ;
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
