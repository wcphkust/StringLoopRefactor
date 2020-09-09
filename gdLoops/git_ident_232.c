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
  int len = strlen(src);
  char c;
  // git-2.18.0/ident.c:232:2
  while (len > 0) {
    c = src[len - 1];
    if (!crud(c))
      break;
    --len;
  }

  return src + len;
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
