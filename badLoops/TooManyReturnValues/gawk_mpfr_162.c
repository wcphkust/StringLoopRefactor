#include <stdio.h>
#include <string.h>
#define N 10

//C: too many vars, goto
char *loopFunction(char *str) {
  // gawk-4.2.0/mpfr.c:162:2
  while (len > 0) {
    switch (*s) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
      break;
    case '8':
    case '9':
      if (base == 8)
        goto done;
      break;
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
      if (base == 16)
        break;
    default:
      goto done;
    }
    s++;
    len--;
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
