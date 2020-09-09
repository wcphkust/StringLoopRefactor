#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *temp, char* pathname) {
  // bash-4.4/lib/readline/complete.c:739:7
  char *x;
  for (x = temp - 1; x > pathname; x--)
    if (*x == '/')
      break;

  return x;
}

void driver() {
  char str[N];
  klee_make_symbolic(str, sizeof(str), "str");

  char* temp = strrchr (str, '/');

  char *p = loopFunction(temp, str);
#ifdef DRIVER
#include "driver.c"
#endif
}

#ifdef MAIN_FUNC
#include "main.c"
#endif
