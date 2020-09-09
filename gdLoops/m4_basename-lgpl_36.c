#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

# define ISSLASH(C) ((C) == '/' || (C) == '\\')
char *loopFunction(char *base) {
  // m4-1.4.18/lib/basename-lgpl.c:36:3
  while (ISSLASH(*base))
    base++;
  return base;
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
