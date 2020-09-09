#include <stdio.h>
#include <string.h>
#define STR_SIZE 10

#define whitespace(c) (((c) == ' ') || ((c) == '\t'))

char* loopFunction(char* line) {
// bash-4.4/bashhist.c:607:3 
    char *p;
    for (p = line; p && *p && whitespace (*p); p++)
      ;
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
