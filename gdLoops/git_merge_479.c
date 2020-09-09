#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *remote) {
  // git-2.18.0/builtin/merge.c:479:2
  char* ptr;
  int len;
  for (len = 0, ptr = remote + strlen(remote); remote < ptr && ptr[-1] == '^';
       ptr--)
    len++;
  return ptr;
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
