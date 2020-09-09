#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

static int crud(unsigned char c)
{
	return  c <= 32  ||
		c == '.' ||
		c == ',' ||
		c == ':' ||
		c == ';' ||
		c == '<' ||
		c == '>' ||
		c == '"' ||
		c == '\\' ||
		c == '\'';
}
char *loopFunction(char *src) {
  char c;
  // git-2.18.0/ident.c:224:2
  while ((c = *src) != 0) {
    if (!crud(c))
      break;
    src++;
  }
  return src;
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
