#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

static inline int mingw_is_dir_sep(int c)
{
	return c == '/' || c == '\\';
}
#define is_dir_sep mingw_is_dir_sep

char *loopFunction(char *start) {
  // git-2.18.0/abspath.c:40:2
  for (; is_dir_sep(*start); start++)
    ; /* nothing */
  return start;
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
