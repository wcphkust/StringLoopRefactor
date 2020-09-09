#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop
char *loopFunction(char *str) {
  // bash-4.4/general.c:1055:3
  for (r = s; *r && *r != '/'; r++) {
    /* Short-circuit immediately if we see a quote character.  Even though
 POSIX says that `the first unquoted slash' (or `:') terminates the
 tilde-prefix, in practice, any quoted portion of the tilde prefix
 will cause it to not be expanded. */
    if (*r == '\\' || *r == '\'' || *r == '"') {
      ret = savestring(s);
      if (lenp)
        *lenp = 0;
      return ret;
    } else if (flags && *r == ':')
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
