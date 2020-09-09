#include <stdio.h>
#include <string.h>
#define N 10
static inline int mingw_is_dir_sep(int c)
{
	return c == '/' || c == '\\';
}
#define is_dir_sep mingw_is_dir_sep
char *loopFunction(char *dir, char* end) {
  // git-2.18.0/builtin/clone.c:315:2
  while (dir < end - 1 && is_dir_sep(end[-1]))
    end--;
  return end;
}

void driver() {
  char str[N];
  klee_make_symbolic(str, sizeof(str), "str");

  char *p = loopFunction(str, str+N);
#ifdef DRIVER
#include "driver.c"
#endif
}

#ifdef MAIN_FUNC
#include "main.c"
#endif
