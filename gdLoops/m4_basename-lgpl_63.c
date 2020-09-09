#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

# define ISSLASH(C) ((C) == '/' || (C) == '\\')
char *loopFunction(char *name) {
  // m4-1.4.18/lib/basename-lgpl.c:63:3
  int len;
  for (len = strlen(name); 1 < len && ISSLASH(name[len - 1]); len--)
    continue;
  return name + len;
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
