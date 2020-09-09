#include <stdio.h>
#include <string.h>
#define N 10

//C: sideffects, structs
char *loopFunction(char *str) {
  // git-2.18.0/combine-diff.c:1213:3
  for (i = 0; i < num_parent; i++)
    putchar(p->parent[i].status);
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
