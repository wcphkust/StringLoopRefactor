#include <stdio.h>
#include <string.h>
#define N 10

//C: invalid return type
char *loopFunction(char *str) {
  // sed-4.4/sed/compile.c:306:3
  for (p = buf + 1; p < bufend && max <= 255; ++p, max *= base) {
    int d = -1;
    switch (*p) {
    case '0':
      d = 0x0;
      break;
    case '1':
      d = 0x1;
      break;
    case '2':
      d = 0x2;
      break;
    case '3':
      d = 0x3;
      break;
    case '4':
      d = 0x4;
      break;
    case '5':
      d = 0x5;
      break;
    case '6':
      d = 0x6;
      break;
    case '7':
      d = 0x7;
      break;
    case '8':
      d = 0x8;
      break;
    case '9':
      d = 0x9;
      break;
    case 'A':
    case 'a':
      d = 0xa;
      break;
    case 'B':
    case 'b':
      d = 0xb;
      break;
    case 'C':
    case 'c':
      d = 0xc;
      break;
    case 'D':
    case 'd':
      d = 0xd;
      break;
    case 'E':
    case 'e':
      d = 0xe;
      break;
    case 'F':
    case 'f':
      d = 0xf;
      break;
    }
    if (d < 0 || base <= d)
      break;
    n = n * base + d;
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
