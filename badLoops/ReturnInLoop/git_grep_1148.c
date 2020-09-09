#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop
char *loopFunction(char *str) {
  // git-2.18.0/grep.c:1148:2
  while (bol < --eol) {
    if (*eol != '>')
      continue;
    *eol_p = ++eol;
    ch = *eol;
    *eol = '\0';
    return ch;
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
