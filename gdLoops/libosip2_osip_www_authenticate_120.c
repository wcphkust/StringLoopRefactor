#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *tmp) {
  // libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:120:9
  for (; *tmp == ' ' || *tmp == '\t'; tmp++) {
  }
  return tmp;
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
