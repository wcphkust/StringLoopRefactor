#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop
char *loopFunction(char *sp) {
  // gawk-4.2.0/ext.c:91:2
  for (sp++; (c = *sp++) != '\0';) {
    if (!is_identchar(c))
      return false;
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
