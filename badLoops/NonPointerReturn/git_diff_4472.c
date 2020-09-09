#include <stdio.h>
#include <string.h>
#define N 10

//C: complex return
char *loopFunction(char *str) {
  // git-2.18.0/diff.c:4472:3
  for (i = 0; (optch = optarg[i]) != '\0'; i++) {
    if (optch < 'a' || 'z' < optch)
      continue;
    opt->filter = (1 << (ARRAY_SIZE(diff_status_letters) - 1)) - 1;
    opt->filter &= ~filter_bit[DIFF_STATUS_FILTER_AON];
    break;
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
