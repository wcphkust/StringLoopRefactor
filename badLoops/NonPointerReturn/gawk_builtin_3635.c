#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return value
char *loopFunction(char *str) {
  // gawk-4.2.0/builtin.c:3635:3
  for (str += 2, len -= 2; len > 0; len--, str++) {
    switch (*str) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      val = *str - '0';
      break;
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
      val = *str - 'a' + 10;
      break;
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
      val = *str - 'A' + 10;
      break;
    default:
      if (endptr)
        *endptr = str;
      goto done;
    }
    retval = (retval * 16) + val;
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
