#include <assert.h>
#include <time.h>
#include <stdlib.h>
void klee_make_symbolic(char* p, size_t i,  const char* c ){}
void klee_assume(int i) {}
char *loopFunctionProg(char* s);


//Need to have >,\n in each test case as otherwise some original loops don't stop
const char* testCases[] = { 
//"a054353 345345 433,",
"054f353 34/534>5 4\n33sf,",
"/\\///\\///54f35\n3 34/5345> 433sf,",
"5\n4f353 34/5345 43>3sf,",
//"054f353 34/5345/433,",
"  \tts\ndfjlkssd;jf>nskd.fsa",
//"fsdgfdgf\f5r\t'",
"                                                                                 >\n      s"
};

volatile char* p;
volatile int e;

#define TEST_REPS 10000000

int main(int argc, char** argv) {

    char *p1, *p2;
    for(int i = 0; i < sizeof(testCases)/sizeof(testCases[0]); i++) {
         p1 = loopFunction((char*)testCases[i]);
         p2 = loopFunctionProg((char*)testCases[i]);
         if(p1 != p2) {
             printf("test case FAILED!!!\n");
             printf("summary start %p original %p, prog: %p on %s\n",testCases[i],p1, p2, testCases[i]);
             abort();
         }
    }

    double endTime, startTime = (double)clock()/CLOCKS_PER_SEC;
    for(int j = 0; j < TEST_REPS; j++) {
        for(int i = 0; i < sizeof(testCases)/sizeof(testCases[0]); i++) {
         p = loopFunction((char*)testCases[i]);
        }
    }

    endTime = (double)clock()/CLOCKS_PER_SEC;
    double timeElapse = endTime - startTime;
    printf("Loop function took %f seconds\n", timeElapse);
    startTime = (double)clock()/CLOCKS_PER_SEC;

    for(int j = 0; j < TEST_REPS; j++) {
        for(int i = 0; i < sizeof(testCases)/sizeof(testCases[0]); i++) {
          //e = strspn(testCases[i], "0123456789");
//          p = strrchr(testCases[i], '/');

            p = loopFunctionProg((char*)testCases[i]);
        }
    }
    endTime = (double)clock()/CLOCKS_PER_SEC;
    printf("Native took %f seconds\n", endTime - startTime);
    printf("Speedup %f\n", timeElapse / (endTime - startTime));
    printf("summary %f %f %f\n", timeElapse, endTime - startTime, timeElapse/(endTime - startTime));
    return 0;
}
