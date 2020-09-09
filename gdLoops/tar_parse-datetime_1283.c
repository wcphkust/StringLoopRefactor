#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define STR_SIZE 10
bool
c_isspace (int c)
{
  switch (c)
    {
    case ' ': case '\t': case '\n': case '\v': case '\f': case '\r':
      return true;
    default:
      return false;
    }
}

char *loopFunction(char *p) {
  // tar-1.29/gnu/parse-datetime.y:1283:3
  char c;
  while (c = *p, c_isspace(c))
    p++;
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
