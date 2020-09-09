#include <stdio.h>
#include <string.h>
#define N 10

//C: has goto
char *loopFunction(char *str) {
  // make-4.2/job.c:2615:5
  for (cap = ifs; *cap != '\0'; ++cap)
    if (*cap != ' ' && *cap != '\t' && *cap != '\n')
      goto slow;
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
