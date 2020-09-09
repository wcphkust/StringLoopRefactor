#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

# define _IS_DRIVE_LETTER(C) (((unsigned int) (C) | ('a' - 'A')) - 'a'  \
                              <= 'z' - 'a')
# define FILE_SYSTEM_PREFIX_LEN(Filename) \
          (_IS_DRIVE_LETTER ((Filename)[0]) && (Filename)[1] == ':' ? 2 : 0)
# define ISSLASH(C) ((C) == '/' || (C) == '\\')
char *loopFunction(char *filename) {
  // patch-2.7/src/util.c:1230:3
  char *f;
  for (f = filename + FILE_SYSTEM_PREFIX_LEN(filename); ISSLASH(*f); f++)
    /* do nothing */;
  return f;
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
