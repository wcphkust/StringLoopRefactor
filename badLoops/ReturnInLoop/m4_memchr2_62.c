#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop
char *loopFunction(char *str) {
  // m4-1.4.18/lib/memchr2.c:62:3
  for (void_ptr = s; n > 0 && (uintptr_t)void_ptr % sizeof(longword) != 0;
       --n) {
    char_ptr = void_ptr;
    if (*char_ptr == c1 || *char_ptr == c2)
      return (void *)void_ptr;
    void_ptr = char_ptr + 1;
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
