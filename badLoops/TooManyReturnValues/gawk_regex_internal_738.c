#include <stdio.h>
#include <string.h>
#define N 10

//C: too many vars
char *loopFunction(char *str) {
  // gawk-4.2.0/support/regex_internal.c:738:7
  for (; p >= end; --p)
    if ((*p & 0xc0) != 0x80) {
      mbstate_t cur_state;
      wchar_t wc2;
      int mlen = raw + pstr->len - p;
      unsigned char buf[6];
      size_t mbclen;

      const unsigned char *pp = p;
      if (BE(pstr->trans != NULL, 0)) {
        int i = mlen < 6 ? mlen : 6;
        while (--i >= 0)
          buf[i] = pstr->trans[p[i]];
        pp = buf;
      }
      /* XXX Don't use mbrtowc, we know which conversion
         to use (UTF-8 -> UCS4).  */
      memset(&cur_state, 0, sizeof(cur_state));
      mbclen = __mbrtowc(&wc2, (const char *)pp, mlen, &cur_state);
      if (raw + offset - p <= mbclen && mbclen < (size_t)-2) {
        memset(&pstr->cur_state, '\0', sizeof(mbstate_t));
        pstr->valid_len = mbclen - (raw + offset - p);
        wc = wc2;
      }
      break;
    }
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
