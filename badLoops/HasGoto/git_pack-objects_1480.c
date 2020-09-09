#include <stdio.h>
#include <string.h>
#define N 10

//C: loop has goto
char *loopFunction(char *str) {
  // git-2.18.0/builtin/pack-objects.c:1480:4
  while (c & 128) {
    ofs += 1;
    if (!ofs || MSB(ofs, 7)) {
      error("delta base offset overflow in pack for %s",
            oid_to_hex(&entry->idx.oid));
      goto give_up;
    }
    c = buf[used_0++];
    ofs = (ofs << 7) + (c & 127);
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
