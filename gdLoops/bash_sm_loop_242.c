#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

#define L(CS)	CS
char* loopFunction(char* n) {
// bash-4.4/lib/glob/sm_loop.c:242:8
  char* se = strlen(n);
  while (n < se && *n != L('/'))
    ++n;
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
