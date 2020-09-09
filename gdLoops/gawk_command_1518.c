#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *p) {
  int i;
  int len = strlen(p);
  // gawk-4.2.0/command.y:1518:2
  for (i = 0; i < len; i++, p++)
    if (*p != ' ' && *p != '\t')
      break;
  return p;
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
