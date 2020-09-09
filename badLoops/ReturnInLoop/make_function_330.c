#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop, many return values
char *loopFunction(char *str) {
  // make-4.2/function.c:330:3
  for (; ptr < end; ++ptr)
    if (*ptr == startparen)
      ++count;

    else if (*ptr == endparen) {
      --count;
      if (count < 0)
        return NULL;
    }

    else if (*ptr == ',' && !count)
      return (char *)ptr;
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
