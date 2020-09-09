#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

int is_urlschemechar(int first_flag, int ch)
{
	/*
	 * The set of valid URL schemes, as per STD66 (RFC3986) is
	 * '[A-Za-z][A-Za-z0-9+.-]*'. But use sightly looser check
	 * of '[A-Za-z0-9][A-Za-z0-9+.-]*' because earlier version
	 * of check used '[A-Za-z0-9]+' so not to break any remote
	 * helpers.
	 */
	int alphanumeric, special;
	alphanumeric = ch > 0 && isalnum(ch);
	special = ch == '+' || ch == '-' || ch == '.';
	return alphanumeric || (!first_flag && special);
}
char *loopFunction(char *url) {
  char* p = url;
  // git-2.18.0/transport.c:892:3
  while (is_urlschemechar(p == url, *p))
    p++;
  return p;
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
