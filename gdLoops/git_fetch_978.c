#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *url) {
  int i;
  int url_len = strlen(url);
  // git-2.18.0/builtin/fetch.c:978:2
  for (i = url_len - 1; url[i] == '/' && 0 <= i; i--)
    ;
  return url + i;
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
