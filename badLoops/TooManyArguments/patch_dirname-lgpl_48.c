#include <stdio.h>
#include <string.h>
#define N 10

# define ISSLASH(C) ((C) == '/' || (C) == '\\')
//C: too complicated dependant function
char *loopFunction(char *file) {
  // patch-2.7/lib/dirname-lgpl.c:48:3
  /* Strip the basename and any redundant slashes before it.  */
  int length;
  for (length = last_component(file) - file; prefix_length < length; length--)
    if (!ISSLASH(file[length - 1]))
      break;
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
