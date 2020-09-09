#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

char *loopFunction(char *pbeg) {
  // libosip2-4.1.0/src/osipparser2/osip_port.c:563:3
  while ((' ' == *pbeg) || ('\r' == *pbeg) || ('\n' == *pbeg) ||
         ('\t' == *pbeg))
    pbeg++;
 return pbeg;
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
