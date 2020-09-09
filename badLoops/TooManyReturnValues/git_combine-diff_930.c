#include <stdio.h>
#include <string.h>
#define N 10

//C: too many return values
char *loopFunction(char *str) {
  // git-2.18.0/combine-diff.c:930:3
  for (i = 0; added && i < num_parent; i++)
    if (elem->parent[i].status != DIFF_STATUS_ADDED)
      added = 0;
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
