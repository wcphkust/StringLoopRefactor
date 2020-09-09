#include <stdio.h>
#include <string.h>
#define N 10

//C: multiple return values
char *loopFunction(char *str) {
  // git-2.18.0/sha1-name.c:1698:2
  for (cp = name, bracket_depth = 0; *cp; cp++) {
    if (*cp == '{')
      bracket_depth++;
    else if (bracket_depth && *cp == '}')
      bracket_depth--;
    else if (!bracket_depth && *cp == ':')
      break;
  }
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
