#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

# define ISSEP(c) ((c) == '/')
char *loopFunction(char *val) {
  // wget-1.9/src/init.c:758:7
  for (++val; ISSEP(*val); val++)
    ;
  return val;
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
