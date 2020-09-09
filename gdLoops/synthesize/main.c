#include "interpreter.c"

int main() {
    char **counterexample = calloc(sizeof(char*), MAX_TESTCASES);
    int next_test_case = 0;
    char *prog;

    char *s, *o, *m;

    do {
        printf("Attempt #%d\n", next_test_case);

        prog = malloc(PROGRAM_MAX_SIZE);
        klee_make_symbolic(prog, PROGRAM_MAX_SIZE, "program");

        //Constrain prog to current counter examples
        for(int j = 0; j < next_test_case; j++) {
            char* cex = counterexample[j];
            char *ret = interpreter(cex, prog);
            char *orig = loopFunction(cex);
            if(orig != ret) klee_silent_exit(0);
        }
        klee_kill_all_other();
        //Concretize prog
        printf("PROG: ");
        for(int k = 0; k < PROGRAM_MAX_SIZE; k++) {
            prog[k] = klee_get_valuel(prog[k]);
            printf("%c", prog[k]);
        }
        printf("END\n");

        //Find new counterexample
        s = malloc(EXAMPLE_MAX_SIZE);
        klee_make_symbolic(s, EXAMPLE_MAX_SIZE, "s");
        s[EXAMPLE_MAX_SIZE - 1] = '\0';
        
        klee_open_merge();
        o = loopFunction(s);
        m = interpreter(s, prog);
        klee_close_merge();

        int results_the_same = (o == m);

        //If there is a single solution to 0 == m and that
        //solution is that they are equal, we are done!
        if ((klee_is_symbolic(results_the_same) == 0)
            & (o == m)) {
            break;
        }
        
        free(prog);
        //otherwise we add a counterexample
        if(results_the_same == 0) {
            //concretize the counterexample
       //     printf("CEX:");
            for(int n = 0; n < EXAMPLE_MAX_SIZE; n++) {
                s[n] = klee_get_valuel(s[n]);
       //         printf("%c", s[n]);
            }
       //     printf("END\n");

            counterexample[next_test_case] = s;
            next_test_case++;
            if(next_test_case >= MAX_TESTCASES) 
                assert(0 && "Too small counterexample array");
        
        } else {
            //prune the paths where results are the same
            klee_silent_exit(0);
        }

    } while(1);


    printf("FOUND the program: ");
    for(int k = 0; k < PROGRAM_MAX_SIZE; k++) {
        prog[k] = klee_get_valuel(prog[k]);
        printf("%c", prog[k]);
    }
    printf("END!\n");


    assert(0 && "Found it! Stopping!");

    return 0;
}
