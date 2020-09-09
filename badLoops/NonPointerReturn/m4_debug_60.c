#include <stdio.h>
#include <string.h>
#define N 10

//C: invalid return type
char *loopFunction(char *str) {
  // m4-1.4.18/src/debug.c:60:7

  for (level = 0; *opts; opts++) {
    switch (*opts) {
    case 'a':
      level |= DEBUG_TRACE_ARGS;
      break;

    case 'e':
      level |= DEBUG_TRACE_EXPANSION;
      break;

    case 'q':
      level |= DEBUG_TRACE_QUOTE;
      break;

    case 't':
      level |= DEBUG_TRACE_ALL;
      break;

    case 'l':
      level |= DEBUG_TRACE_LINE;
      break;

    case 'f':
      level |= DEBUG_TRACE_FILE;
      break;

    case 'p':
      level |= DEBUG_TRACE_PATH;
      break;

    case 'c':
      level |= DEBUG_TRACE_CALL;
      break;

    case 'i':
      level |= DEBUG_TRACE_INPUT;
      break;

    case 'x':
      level |= DEBUG_TRACE_CALLID;
      break;
    }
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
