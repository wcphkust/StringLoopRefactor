#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

# define ISSLASH(C) ((C) == '/' || (C) == '\\')
char *loopFunction(char *name) {
  // tar-1.29/src/create.c:587:3
  int length = strlen(name);
  int i;
  for (i = length - 1; i > 0; i--)
    if (ISSLASH(name[i]))
      break;
  return name + i;
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
