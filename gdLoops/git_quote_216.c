#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

int quote_path_fully = 1;
#define X8(x)   x, x, x, x, x, x, x, x
#define X16(x)  X8(x), X8(x)
static signed char const sq_lookup[256] = {
	/*           0    1    2    3    4    5    6    7 */
	/* 0x00 */   1,   1,   1,   1,   1,   1,   1, 'a',
	/* 0x08 */ 'b', 't', 'n', 'v', 'f', 'r',   1,   1,
	/* 0x10 */ X16(1),
	/* 0x20 */  -1,  -1, '"',  -1,  -1,  -1,  -1,  -1,
	/* 0x28 */ X16(-1), X16(-1), X16(-1),
	/* 0x58 */  -1,  -1,  -1,  -1,'\\',  -1,  -1,  -1,
	/* 0x60 */ X16(-1), X8(-1),
	/* 0x78 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,   1,
	/* 0x80 */ /* set to 0 */
};

static inline int sq_must_quote(char c)
{
	return sq_lookup[(unsigned char)c] + quote_path_fully > 0;
}
char *loopFunction(char *s) {
  int len;
  // git-2.18.0/quote.c:216:3
  for (len = 0; !sq_must_quote(s[len]); len++)
    ;
  return s + len;
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
