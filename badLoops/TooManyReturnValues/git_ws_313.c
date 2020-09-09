#include <stdio.h>
#include <string.h>
#define N 10

//C: too many variables
char *loopFunction(char *str) {
  // git-2.18.0/ws.c:313:2
  /*
   * Check leading whitespaces (indent)
   */
  for (i = 0; i < len; i++) {
    char ch = src[i];
    if (ch == '\t') {
      last_tab_in_indent = i;
      if ((ws_rule & WS_SPACE_BEFORE_TAB) && 0 <= last_space_in_indent)
        need_fix_leading_space = 1;
    } else if (ch == ' ') {
      last_space_in_indent = i;
      if ((ws_rule & WS_INDENT_WITH_NON_TAB) &&
          ws_tab_width(ws_rule) <= i - last_tab_in_indent)
        need_fix_leading_space = 1;
    } else
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
