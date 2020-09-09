#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

#define ISDIGIT(c) ((unsigned) (c) - '0' <= 9)
char *loopFunction(char *name) {
  // make 4.2/variable.c:298:7
  for (++name; *name != '\0'; ++name)
    if (*name != '_' && (*name < 'a' || *name > 'z') &&
        (*name < 'A' || *name > 'Z') && !ISDIGIT(*name))
      break;
  return name;
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
