#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *path) {
  // git-2.18.0/read-cache.c:662:3
  int namelen = strlen(path);
  while (namelen && path[namelen - 1] == '/')
    namelen--;

  return path + namelen;
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
