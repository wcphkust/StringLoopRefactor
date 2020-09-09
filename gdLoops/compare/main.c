#include <string.h>
#include <stdlib.h>
#include "../synthesize/interpreter.c"
#include <assert.h>
#include <stdio.h>
void markString(char*  s){}
void klee_make_symbolic(void*, int, char*);
size_t strlen(const char *str) {
      const char *s = str;
        while (*s)
                ++s;
        return s - str;
}


int main(int argc, char** argv) {
    assert(argc == 2 && "verify needs a program as argument");

    char *s = malloc(EXAMPLE_MAX_SIZE);
    char *m;


    char prog[PROGRAM_MAX_SIZE + 1];
    prog[PROGRAM_MAX_SIZE] = '\0';
    FILE *f = fopen(argv[1], "rb");
    assert(f && "can't read file");
    int n = fread(prog,1,PROGRAM_MAX_SIZE,f);
    assert(n == PROGRAM_MAX_SIZE && "didn't read the whole program");
    fclose(f);
    printf("Running on %d  program %s\n",n,  prog);

    klee_make_symbolic(s, EXAMPLE_MAX_SIZE, "s");
    markString(s);
    s[EXAMPLE_MAX_SIZE - 1] = '\0';
    m = interpreter(s, prog);

    return 0;
}
