#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *path) {
  // wget-1.9/src/url.c:1255:3
  char *p = path + strlen(path);
  for (; *p != '/' && p != path; p--)
    ;
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
