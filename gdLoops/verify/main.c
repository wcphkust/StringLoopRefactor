#include "../synthesize/interpreter.c"
#include <assert.h>

int main(int argc, char** argv) {
    assert(argc == 2 && "verify needs a program as argument");

    char *s = malloc(EXAMPLE_MAX_SIZE);
    char *o, *m;


    char prog[PROGRAM_MAX_SIZE + 1];
    prog[PROGRAM_MAX_SIZE] = '\0';
    FILE *f = fopen(argv[1], "rb");
    assert(f && "can't read file");
    int n = fread(prog,1,PROGRAM_MAX_SIZE,f);
    //assert(n == PROGRAM_MAX_SIZE && "didn't read the whole program");
    fclose(f);
    printf("Running on %d  program %s\n",n,  prog);

    klee_make_symbolic(s, EXAMPLE_MAX_SIZE, "s");
    s[EXAMPLE_MAX_SIZE - 1] = '\0';
    
    o = loopFunction(s);
    m = interpreter(s, prog);

    printf("s: %p original %p, mine %p \n",s,  o, m);
    assert(o == m && "Found a bug with  syntehesized program!");

    return 0;
}
