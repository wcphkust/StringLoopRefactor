#include <stdio.h>
#include <string.h>
#define N 10

//C: Return in loop
char *loopFunction(char *str) {
  // git-2.18.0/sha1-file.c:1117:2
  for (;;) {
    char c = *hdr++;
    if (!c)
      return -1;
    if (c == ' ')
      break;
    type_len++;
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
