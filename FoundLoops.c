//m4-1.4.18/src/builtin.c:1458:7

int len = strlen (str);
for (i = len; i > 1; i--)
    if (str[i - 1] != 'X')
       break;


//m4-1.4.18/src/builtin.c:1412:3

/* len passed in separately */

for (i = 0; len > 0 && i < 6; i++)
  if (pattern[len - i - 1] != 'X')
    break;


//m4-1.4.18/src/debug.c:60:7

for (level = 0; *opts; opts++)
        {
          switch (*opts)
            {
            case 'a':
              level |= DEBUG_TRACE_ARGS;
              break;

            case 'e':
              level |= DEBUG_TRACE_EXPANSION;
              break;

            case 'q':
              level |= DEBUG_TRACE_QUOTE;
              break;

            case 't':
              level |= DEBUG_TRACE_ALL;
              break;

            case 'l':
              level |= DEBUG_TRACE_LINE;
              break;

            case 'f':
              level |= DEBUG_TRACE_FILE;
              break;

            case 'p':
              level |= DEBUG_TRACE_PATH;
              break;

            case 'c':
              level |= DEBUG_TRACE_CALL;
              break;

            case 'i':
              level |= DEBUG_TRACE_INPUT;
              break;

            case 'x':
              level |= DEBUG_TRACE_CALLID;
              break;
	}
}

//m4-1.4.18/src/symtab.c:131:3
while ((ch = *ptr++) != '\0')
  val = (val << 7) + (val >> (sizeof (val) * CHAR_BIT - 7)) + ch;



//m4-1.4.18/src/clean-temp.c:175:3
  for (; *s; s++)
    h = *s + ((h << 9) | (h >> (SIZE_BITS - 9)));


//m4-1.4.18/lib/filenamecat-lgpl.c:40:3
  for (f += FILE_SYSTEM_PREFIX_LEN (f); ISSLASH (*f); f++)
    continue;


//m4-1.4.18/lib/memchr2.c:162:3

  for (; n > 0; --n, ++char_ptr)
    {
      if (*char_ptr == c1 || *char_ptr == c2)
        return (void *) char_ptr;
    }


//m4-1.4.18/lib/memchr2.c:62:3
  for (void_ptr = s;
       n > 0 && (uintptr_t) void_ptr % sizeof (longword) != 0;
       --n)
    {
      char_ptr = void_ptr;
      if (*char_ptr == c1 || *char_ptr == c2)
        return (void *) void_ptr;
      void_ptr = char_ptr + 1;
    }



//m4-1.4.18/lib/basename-lgpl.c:36:3

  while (ISSLASH (*base))
    base++;



//m4-1.4.18/lib/basename-lgpl.c:39:3
for (p = base; *p; p++)
    {
      if (ISSLASH (*p))
        saw_slash = true;
      else if (saw_slash)
        {
          base = p;
          saw_slash = false;
        }
    }



//m4-1.4.18/lib/basename-lgpl.c:63:3

 for (len = strlen (name);  1 < len && ISSLASH (name[len - 1]);  len--)
    continue;


//make-4.2/ar.c:232:3
 for (p = pattern; *p != '\0'; ++p)
    switch (*p)
      {   
      case '?':
      case '*':
        return 1;

      case '\\':
        if (quote)
          ++p;
        break;

      case '[':
        opened = 1;
        break;

      case ']':
        if (opened)
          return 1;
        break;
      }   


//make-4.2/file.c:902:3
 p += strlen (p) - 1;
  while (*p == '0')
    p--;


//make-4.2/function.c:2456:3

  for (nargs=1, end=beg; *end != '\0'; ++end)
    if (*end == ',')
      ++nargs;
    else if (*end == openparen)
      ++count;
    else if (*end == closeparen && --count < 0)
      break;


//make-4.2/function.c:330:3
 for (; ptr < end; ++ptr)
    if (*ptr == startparen)
      ++count;

    else if (*ptr == endparen)
      {
        --count;
        if (count < 0)
          return NULL;
      }

    else if (*ptr == ',' && !count)
      return (char *)ptr;


//make-4.2/job.c:2615:5
   for (cap = ifs; *cap != '\0'; ++cap)
      if (*cap != ' ' && *cap != '\t' && *cap != '\n')
        goto slow;


//make-4.2/misc.c:61:3
 in = strchr (line, '\n');
  if (in == 0)
    return;

  out = in;
  while (out > line && out[-1] == '\\')
    --out;


//make-4.2/misc.c:309:3
while (s < limit)
    if (*s++ == c)
      return (char *)(s - 1);


//make-4.2/read.c:1780:11
for (line = s2; *line != '\0'; ++line)
  {
    if (*line == '(')
      ++count;
    else if (*line == ')')
      {
        if (count <= 0)
          break;
        else
          --count;
      }
  }




//make-4.2/read.c:1797:11
while (*line != '\0' && *line != termin)
            ++line;


//make-4.2/read.c:1734:11
for (; *line != '\0'; ++line)
      if (*line == '(')
        ++count;
      else if (*line == ')')
        --count;
      else if (*line == ',' && count <= 0)
        break;


//make 4.2/variable.c:298:7
for (++name; *name != '\0'; ++name)
     if (*name != '_' && (*name < 'a' || *name > 'z')
         && (*name < 'A' || *name > 'Z') && !ISDIGIT(*name))
       break;


//make-4.2/variable.c:1681:9
for (p = v->value; *p != '\0'; ++p)
     {
       if (*p == '$')
         putchar ('$');
       putchar (*p);
     }



//wget-1.9/src/convert.c:538:3
 for (; beg < end; beg++)
    {
      switch (*beg)
  {
  case '&': 
    saw_amp = 1;
    break;
  case '#':
    if (!saw_amp)
      {
        *bp = beg;
        *ep = end;
        return 1;
      }
    /* fallthrough */
  default:
    saw_amp = 0;
  } 
    }

//wget-1.9/src/ftp-basic.c:208:9
for (cp = respline + strlen (skey_head[i]);
     '0' <= *cp && *cp <= '9';
     cp++)
  {
    skey_sequence = skey_sequence * 10 + *cp - '0';
  }



//wget-1.9/src/hash.c:553:5        
   for (p += 1; *p != '\0'; p++)
      h = (h << 5) - h + *p;

//wget-1.9/src/headers.c:203:3
 while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n')
    ++p;

//wget-1.9/src/html-parse.c:475:3
while (state != AC_S_DONE && state != AC_S_BACKOUT)
    {
      if (p == end)
  state = AC_S_BACKOUT;
      switch (state)
  {
  case AC_S_DONE:
  case AC_S_BACKOUT:
    break;
  case AC_S_BANG:
    if (ch == '!')
      {
        ch = *p++;
        state = AC_S_DEFA

...

//wget-1.9/src/http.c:2327:7
for (ep = cp; *ep && *ep != '\"'; ep++);

//wget-1.9/src/init.c:758:7
  for (++val; ISSEP (*val); val++)
  ;


//wget-1.9/src/url.c:532:3
 for (p = url; *p && *p != ':' && *p != '/'; p++)
    ;

//wget-1.9/src/url.c:1255:3
 p = path + strlen (path);
  for (; *p != '/' && p != path; p--)
    ;

//wget-1.9/src/url.c:1617:3
 for (; e > b; e--)
    if (*e == c)
      return e;



//wget-1.9/src/utils.c:352:3
 for (p = string; *p; p++)
    if (*p == chr)
      ++count;

//wget-1.9/src/utils.c:712:3

int l = strlen (s);
while (l && s[l] != '/')
    --l;

//wget-1.9/src/utils.c:882:3
for (; *s; s++)
    if (*s == '*' || *s == '?' || *s == '[' || *s == ']')
      return 1;

//wget-1.9/src/utils.c:1752:3
 for (i = 0; *s; s++, i++)
    {
      if (*s == '&')
  i += 4;     /* `amp;' */
      else if (*s == '<' || *s == '>')
  i += 3;     /* `lt;' and `gt;' */
      else if (*s == '\"')
  i += 5;     /* `quot;' */
      else if (*s == ' ')
  i += 4;     /* #32; */
    }

//libosip2-4.1.0/src/osipparser2/osip_message_parse.c:331:3
while (('\r' != *soh) && ('\n' != *soh)) {
    if (*soh)
      soh++;
    else {
      OSIP_TRACE (osip_trace (__FILE__, __LINE__, OSIP_ERROR, NULL, "Final CRLF is missing\n"));
      return OSIP_SYNTAXERROR;
    }    
  }

//libosip2-4.1.0/src/osipparser2/osip_message_parse.c:217:5
while ((*hp != '\r') && (*hp != '\n')) {
      if (*hp)
        hp++;
      else {
        OSIP_TRACE (osip_trace (__FILE__, __LINE__, OSIP_ERROR, NULL, "No crlf found\n"));
        return OSIP_SYNTAXERROR;
      }
    }

//libosip2-4.1.0/src/osipparser2/osip_message_parse.c:124:5
    while ((*hp != '\r') && (*hp != '\n')) {
      if (*hp) {
        if ((*hp >= '0') && (*hp <= '9'))
          hp++;
        else if (*hp == '.')
          hp++;
        else {
          OSIP_TRACE (osip_trace (__FILE__, __LINE__, OSIP_ERROR, NULL, "incorrect sip version string\n"));
          osip_free (dest->sip_method);
          dest->sip_method = NULL;
          osip_uri_free (dest->req_uri);
          dest->req_uri = NULL;
          return OSIP_SYNTAXERROR;
        }
      }
      else {
        OSIP_TRACE (osip_trace (__FILE__, __LINE__, OSIP_ERROR, NULL, "No crlf found\n"));
        osip_free (dest->sip_method);
        dest->sip_method = NULL;
        osip_uri_free (dest->req_uri);
        dest->req_uri = NULL;
        return OSIP_SYNTAXERROR;
      }
    }

//libosip2-4.1.0/src/osipparser2/osip_port.c:567:3
 while ((' ' == *pend) || ('\r' == *pend) || ('\n' == *pend) || ('\t' == *pend)) {
    pend--;
    if (pend < pbeg) {
      *word = '\0';
      return OSIP_SUCCESS;
    }
  }

//libosip2-4.1.0/src/osipparser2/osip_port.c:563:3
while ((' ' == *pbeg) || ('\r' == *pbeg) || ('\n' == *pbeg) || ('\t' == *pbeg))
    pbeg++

//libosip2-4.1.0/src/osipparser2/osip_port.c:605:3
while ((*sep != end_separator) && (*sep != '\0') && (*sep != '\r')
         && (*sep != '\n'))
    sep++;

//libosip2-4.1.0/src/osipparser2/osip_port.c:1409:3
while ((c = *str++))
    hash = ((hash << 5) + hash) + c;

//libosip2-4.1.0/src/osipparser2/osip_port.c:1476:3
 while ((' ' == *pend) || ('\r' == *pend) || ('\n' == *pend) || ('\t' == *pend)) {
    pend--;
    if (pend < pbeg) {
      *dst = '\0';
      return dst;
    }
  }

//libosip2-4.1.0/src/osipparser2/osip_port.c:1470:3
  while ((' ' == *pbeg) || ('\r' == *pbeg) || ('\n' == *pbeg) || ('\t' == *pbeg))
    pbeg++;

//libosip2-4.1.0/src/osipparser2/osip_from.c:545:5
 for (; *tmp == '\t' || *tmp == ' '; tmp++) {
    }


//libosip2-4.1.0/src/osipparser2/osip_uri.c:241:5
while (host < port && *host != '[')
      host++;

//libosip2-4.1.0/src/osipparser2/osip_uri.c:237:3
while (tmp > host && *tmp != ']')
    tmp--;

//libosip2-4.1.0/src/osipparser2/osip_uri.c:219:3 
 while (port > host && *port != ']' && *port != ':')
    port--;

//libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:120:9
for (; *tmp == ' ' || *tmp == '\t'; tmp++) {
        }

//libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:109:7
for (; *tmp == ' ' || *tmp == '\t'; tmp++) {
      }

//libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:111:7
for (; *tmp == '\n' || *tmp == '\r'; tmp++) {
} 

//libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:144:7
for (; *tmp == ' ' || *tmp == '\t'; tmp++) {
      }

//libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:135:5 
for (; *tmp == '\n' || *tmp == '\r'; tmp++) {
    }  


//libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:133:5
for (; *tmp == ' ' || *tmp == '\t'; tmp++) {
}

//libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:89:5
 while (' ' == *(hack - 1))  /* get rid of extra spaces */
      hack--;

//libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:72:3
 while ((' ' == *str) || ('\t' == *str) || (',' == *str))
    if (*str)
      str++;
    else
      return OSIP_SYNTAXERROR; 
//libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:207:7
for (; *tmp == ' ' || *tmp == '\t'; tmp++) {
 }
//libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:198:5
for (; *tmp == '\n' || *tmp == '\r'; tmp++) {
    }  
//libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:196:5
for (; *tmp == ' ' || *tmp == '\t'; tmp++) {
}

//libosip2-4.1.0/src/src/osipparser2/osip_www_authenticate.c:174:3
while ((' ' == *str) || ('\t' == *str) || (',' == *str))
    if (*str)
      str++;
    else
      return OSIP_SYNTAXERROR;  /* bad header format */

//patch-2.7/src/inp.c:479:6
for (q = p;  *q++ != '\n';  )
      /* do nothing */ ;

//patch-2.7/src/pch.c:2342:3
while (*p == ' ' || *p == '\t')
        p++;
//patch-2.7/src/pch.c:2312:4
while (ISDIGIT (*++p))
     /* do nothing */ ;

//patch-2.7/src/pch.c:2306:7
while (ISDIGIT (*++p))
  /* do nothing */ ;

//patch-2.7/src/pch.c:387:3
for (s = str; (*s >= '0' && *s <= '9') || (*s >= 'a' && *s <= 'f'); s++)
    /* do nothing */ ;

//patch-2.7/src/pch.c:369:3
for (s = sha1; *s; s++)
    if (*s != '0')
      break;

//patch-2.7/src/pch.c:331:4
for (s = str, mode = 0; s < str + 6; s++)
{
       if (*s >= '0' && *s <= '7')
  mode = (mode << 3) + (*s - '0');
       else
  {
   mode = 0;
   break;
  }
}

//patch-2.7/src/pch.c:1228:6
 while (*s != '\n')
    s++;

//patch-2.7/src/pch.c:1223:2
  while (*s == '*')
      s++;
//patch-2.7/src/pch.c:1631:6
  while (*s != '\n')
    s++;

//patch-2.7/src/pch.c:1140:3
 for (s = s0;  ISDIGIT (*s);  s++)
    {
      lin new_n = 10 * n + (*s - '0');
      overflow |= new_n / 10 != n;
      n = new_n;
    }

//patch-2.7/src/util.c:347:4
for (o = t + tlen, olen = 0;
     o > t && ! ISSLASH (*(o - 1));
     o--)
  /* do nothing */ ;

//patch-2.7/src/util.c:168:3
for (; *s; s++)
    if (ISSLASH(*s))
      return true;

//patch-2.7/src/util.c:1230:3
for (f = filename + FILE_SYSTEM_PREFIX_LEN (filename);  ISSLASH (*f);  f++)
    /* do nothing */ ;

//patch-2.7/lib/dirname-lgpl.c:48:3
 /* Strip the basename and any redundant slashes before it.  */
  for (length = last_component (file) - file;
       prefix_length < length; length--)
    if (! ISSLASH (file[length - 1]))
      break;

//patch-2.7/lib/basename-lgpl.c:39:3
for (p = base; *p; p++)
    {
      if (ISSLASH (*p))
        saw_slash = true;
      else if (saw_slash)
        {
          base = p;
          saw_slash = false;
        }
    }

//patch-2.7/lib/basename-lgpl.c:36:3
  while (ISSLASH (*base))
    base++;

//patch-2.7/lib/hash.c:433:3
  for (; (ch = *string); string++)
    value = (value * 31 + ch) % n_buckets;

//patch-2.7/lib/parse-datetime.y:1283:3
  while ((*yyd++ = *yys++) != '\0')
    continue;

//grep-3.1/src/grep.c:836:3
  for (char const *p = buf; p < buf + size; p++) 
    if (*p) 
      return false;

//grep-3.1/src/searchutils.c:99:9
 for (int i = 1; i <= 3; i++)
          if ((cur[-i] & 0xc0) != 0x80)
            {
              mbstate_t mbs = { 0 };
              size_t clen = mb_clen (cur - i, end - (cur - i), &mbs);
              if (i < clen && clen < (size_t) -2)
                {
                  p0 = cur - i;
                  p = p0 + clen;
                }
              break;
            }

//grep-3.1/lib/exclude.c:552:8
 while (len > 0 && ISSLASH (pattern[len-1]))
    --len;

//grep-3.1/lib/basename-lgpl.c:39:3
for (p = base; *p; p++)
    {
      if (ISSLASH (*p))
        saw_slash = true;
      else if (saw_slash)
        {
          base = p;
          saw_slash = false;
        }
    }

//grep-3.1/lib/basename-lgpl.c:36:3
  while (ISSLASH (*base))
    base++;

//grep-3.1/lib/hash.c:433:3
  for (; (ch = *string); string++)
    value = (value * 31 + ch) % n_buckets;


//grep-3.1/lib/memchr2.c:162:3
  for (; n > 0; --n, ++char_ptr)
    {
      if (*char_ptr == c1 || *char_ptr == c2)
        return (void *) char_ptr;
    }

//grep-3.1/lib/memchr2.c:62:3
 for (void_ptr = s;
       n > 0 && (uintptr_t) void_ptr % sizeof (longword) != 0;
       --n)
    {
      char_ptr = void_ptr;
      if (*char_ptr == c1 || *char_ptr == c2)
        return (void *) void_ptr;
      void_ptr = char_ptr + 1;
    }

//gawk-4.2.0/builtin.c:3635:3
for (str += 2, len -= 2; len > 0; len--, str++) {
      switch (*str) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        val = *str - '0';
        break;
      case 'a':
      case 'b':
      case 'c':
      case 'd':
      case 'e':
      case 'f':
        val = *str - 'a' + 10;
        break;
      case 'A':
      case 'B':
      case 'C':
      case 'D':
      case 'E':
      case 'F':
        val = *str - 'A' + 10;
        break;
      default:
        if (endptr)
          *endptr = str;
        goto done;
      }
      retval = (retval * 16) + val;
    }
//gawk-4.2.0/command.y:1524:3
   for (i++, q = p + 1; i < len; i++, q++)
      if (*q == ' ' || *q == '\t')
        break;

//gawk-4.2.0/command.y:1518:2
for (i = 0; i < len; i++, p++)
    if (*p != ' ' && *p != '\t')
      break;

//gawk-4.2.0/ext.c:91:2
 for (sp++; (c = *sp++) != '\0';) {
    if (! is_identchar(c))
      return false;

//gawk-4.2.0/field.c:448:3
 while (scan < end && (*scan == ' ' || *scan == '\t' || *scan == '\n'))
      scan++;

//gawk-4.2.0/int_array.c:104:2
 while (++s < end) {
    if (*s < '0' || *s > '9')
      return false;

//gawk-4.2.0/io.c:4100:2
  while (*cp != '/' && cp < cpend)
    cp++;

//gawk-4.2.0/io.c:4082:2

  while (*cp != '/') {
    if (++cp >= cpend)
      return false;

//gawk-4.2.0/io.c:4066:2
  while (*cp != '/') {
    if (++cp >= cpend)
      return false;

//gawk-4.2.0/io.c:3461:2 
  while (*bp != rs)
    bp++;

//gawk-4.2.0/main.c:1133:3
for (cp2 = arg+1; *cp2; cp2++)
  if (! is_identchar((unsigned char) *cp2)) {
    badvar = true;
    break;
  }

//gawk-4.2.0/mpfr.c:236:2
  for (; *s != '\0'; s++) {
    if (*s == dec_point || *s == 'e' || *s == 'E')
      return true;

//gawk-4.2.0/mpfr.c:162:2
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
    s++; len--;
  }

//gawk-4.2.0/str_array.c:736:2
while (len--) {
    hashVal += *str++;
    hashVal += (hashVal << 10);
    hashVal ^= (hashVal >> 6);
  }

//gawk-4.2.0/support/getopt.c:952:2
for (d->__nextchar = nameend = d->optarg; *nameend && *nameend != '=';
       nameend++)
//gawk-4.2.0/support/getopt.c:549:7
for (nameend = d->__nextchar; *nameend && *nameend != '='; nameend++)
  /* Do nothing.  */ ;

//gawk-4.2.0/support/regex_internal.c:738:7
for (; p >= end; --p)
  if ((*p & 0xc0) != 0x80)
      {
        mbstate_t cur_state;
        wchar_t wc2;
        int mlen = raw + pstr->len - p;
        unsigned char buf[6];
        size_t mbclen;

        const unsigned char *pp = p;
        if (BE (pstr->trans != NULL, 0))
          {
            int i = mlen < 6 ? mlen : 6;
            while (--i >= 0) 
        buf[i] = pstr->trans[p[i]];
            pp = buf;
          }
        /* XXX Don't use mbrtowc, we know which conversion
           to use (UTF-8 -> UCS4).  */
        memset (&cur_state, 0, sizeof (cur_state));
        mbclen = __mbrtowc (&wc2, (const char *) pp, mlen,
                &cur_state);
        if (raw + offset - p <= mbclen
            && mbclen < (size_t) -2)
          {
            memset (&pstr->cur_state, '\0',
              sizeof (mbstate_t));
            pstr->valid_len = mbclen - (raw + offset - p);
            wc = wc2;
          }
        break;
	}
}

//sed-4.4/sed/compile.c:306:3
  for (p=buf+1; p < bufend && max <= 255; ++p, max *= base)
    {    
      int d = -1;
      switch (*p) 
        {
        case '0': d = 0x0; break;
        case '1': d = 0x1; break;
        case '2': d = 0x2; break;
        case '3': d = 0x3; break;
        case '4': d = 0x4; break;
        case '5': d = 0x5; break;
        case '6': d = 0x6; break;
        case '7': d = 0x7; break;
        case '8': d = 0x8; break;
        case '9': d = 0x9; break;
        case 'A': case 'a': d = 0xa; break;
        case 'B': case 'b': d = 0xb; break;
        case 'C': case 'c': d = 0xc; break;
        case 'D': case 'd': d = 0xd; break;
        case 'E': case 'e': d = 0xe; break;
        case 'F': case 'f': d = 0xf; break;
        }
      if (d < 0 || base <= d)
        break;
      n = n * base + d; 
    } 


//tar-1.29/src/create.c:991:3
 for (i = sizeof *header; i-- != 0; ) 
    /* We can't use unsigned char here because of old compilers, e.g. V7.  */
    sum += 0xFF & *p++;

//tar-1.29/src/create.c:587:3
  for (i = length - 1; i > 0; i--)
    if (ISSLASH (name[i]))
      break;

//tar-1.29/src/xheader.c:356:3
  while (q > buf && ISSLASH (q[-1]))
    q--;

//tar-1.29/src/xheader.c:684:3
  for (p = len_lim; *p == ' ' || *p == '\t'; p++)
    continue;

//tar-1.29/src/xheader.c:662:3 
  while (*p == ' ' || *p == '\t')
    p++;

//tar-1.29/src/list.c:124:3
  for (p = file_name; *p && (ISSLASH (*p) || *p == '.'); p++)
    ;

//tar-1.29/src/list.c:907:4
  while (where0 != lim && ! lim[-1])
    lim--;

//tar-1.29/src/list.c:789:4
    for (;;)
      {
        value += 7 - digit;
        where++;
        if (where == lim || ! ISODIGIT (*where))
    break;
        digit = *where - '0';
        overflow |= value != (value << LG_8 >> LG_8);
        value <<= LG_8;
      }

//tar-1.29/src/list.c:875:7 
      for (;;)
  {
    value = (value << LG_256) + (unsigned char) *where++;
    if (where == lim)
      break;
    if (((value << LG_256 >> LG_256) | topbits) != value)
      {
        if (type && !silent)
    ERROR ((0, 0,
      _("Archive base-256 value is out of %s range"),
      type));
        return -1;
      }
  }

//tar-1.29/src/list.c:354:3
 for (i = sizeof *header; i-- != 0;)
    {
      unsigned_sum += (unsigned char) *p;
      signed_sum += (signed char) (*p++);
    }

//tar-1.29/src/misc.c:505:4
    while (ISDIGIT (*++p))
      if (digits < LOG10_BILLION)
        digits++, ns = 10 * ns + (*p - '0');
      else
        trailing_nonzero |= *p != '0';

//tar-1.29/src/names.c:1805:3
  while (ISSLASH (*p))
    p++;

//tar-1.29/src/sparse.c:193:3
 while (size--)
    if (*buffer++)
      return false;

//tar-1.29/src/utf8.c:95:3
  for (; *p; p++)
    if (*p & ~0x7f)
      return false;


//tar-1.29/lib/paxnames.c:128:7
for (p = file_name + prefix_len; ISSLASH (*p); p++)
  continue;

//tar-1.29/lib/rtapelib.c:169:3
  for (cursor = command_buffer; *cursor; cursor++)
    if (*cursor != ' ')
      break;

//tar-1.29/lib/rtapelib.c:249:7
for (;;)
  {
    int digit = *status++ - '0';
    if (9 < (unsigned) digit)
      break;
    else
      {
        off_t c10 = 10 * count;
        off_t nc = negative ? c10 - digit : c10 + digit;
        if (c10 / 10 != count || (negative ? c10 < nc : nc < c10))
    return -1;
        count = nc;
      }
  }

//tar-1.29/lib/rtapelib.c:243:7
for (;  *status == ' ' || *status == '\t';  status++)
  continue;

//tar-1.29/lib/wordsplit.c:1185:3
  for (p = quote_transtab; *p; p += 2)
    {
      if (*p == c)
  return p[1];
    }

//tar-1.29/lib/wordsplit.c:1198:3
  for (p = quote_transtab + sizeof (quote_transtab) - 2;
       p > quote_transtab; p -= 2)
    {
      if (*p == c)
  return p[-1];
    }

//tar-1.29/lib/wordsplit.c:1123:8
for (j = i + 1; j < len && command[j] != '\n'; j++)
    ;
//tar-1.29/gnu/argp-help.c:343:3
  while (beg < end)
    if (*beg == ch)
      return 1;
    else
      beg++;

//tar-1.29/gnu/dirname-lgpl.c:48:3
  for (length = last_component (file) - file;
       prefix_length < length; length--)
    if (! ISSLASH (file[length - 1]))
      break;

//tar-1.29/gnu/basename-lgpl.c:39:3
  for (p = base; *p; p++)
    {
      if (ISSLASH (*p))
        saw_slash = true;
      else if (saw_slash)
        {
          base = p;
          saw_slash = false;
        }
    }

//tar-1.29/gnu/basename-lgpl.c:36:3
  while (ISSLASH (*base))
    base++;

//tar-1.29/gnu/basename-lgpl.c:63:3
for (len = strlen (name);  1 < len && ISSLASH (name[len - 1]);  len--)
    continue;

//tar-1.29/gnu/exclude.c:552:8
while (len > 0 && ISSLASH (pattern[len-1]))
    --len;

//tar-1.29/gnu/hash.c:433:3
for (; (ch = *string); string++)
    value = (value * 31 + ch) % n_buckets;

//tar-1.29/gnu/modechange.c:169:5
for (p = mode_string; *p; p++)
      needed += (*p == '=' || *p == '+' || *p == '-');

//tar-1.29/gnu/arse-datetime.y:1319:13
while (c = *p, c_isspace (c))
              p++;

//tar-1.29/gnu/parse-datetime.y:1283:3
while (c = *p, c_isspace (c))
    p++;

//tar-1.29/gnu/getopt.c:927:9 
for (d->__nextchar = nameend = d->optarg; *nameend && *nameend != '=';
  nameend++)
  /* Do nothing.  */ ;

//tar-1.29/gnu/getopt.c:507:7
for (nameend = d->__nextchar; *nameend && *nameend != '='; nameend++)
        /* Do nothing.  */ ;
      namelen = nameend - d->__nextchar;

//diffutils-3.6/src/context.c:157:3
while (i < j && c_isspace ((unsigned char) function[j - 1]))
    j--;

//diffutils-3.6/src/context.c:155:3 
for (j = i; j < i + 40 && function[j] != '\n'; j++)
    continue;

//diffutils-3.6/src/ifdef.c:321:5
while (ISDIGIT (c = *f++))
      continue;

//diffutils-3.6/src/ifdef.c:318:3
while (ISDIGIT (c))
    c = *f++;

//diffutils-3.6/src/ifdef.c:316:3
while ((c = *f++) == '-' || c == '\'' || c == '0')
    continue;

//diffutils-3.6/src/ifdef.c:410:2
while ((c = *p++) != '\'')
    {
      unsigned int digit = c - '0';
      if (8 <= digit)
        return NULL;
      value = 8 * value + digit;
    }

//diffutils-3.6/src/io.c:614:3
while (p0 != buffer0 && (p0[-1] != '\n' || i--))
    p0--, p1--;

//diffutils-3.6/src/util.c:768:3
  for (s = str; *s; s++)
    {
      char c = *s;

      if (c == ' ')
  {
    must_quote = true;
    continue;
  }
      switch (c_escape_char (*s))
  {
    case 1:
      plus += 3;
      /* fall through */
    case 0:
      break;
    default:
      plus++;
      break;
  }
    }
//diffutils-3.6/lib/basename-lgpl.c:39:3
  for (p = base; *p; p++)
    {
      if (ISSLASH (*p))
        saw_slash = true;
      else if (saw_slash)
        {
          base = p;
          saw_slash = false;
        }
    }

//diffutils-3.6/lib/basename-lgpl.c:36:3
  while (ISSLASH (*base))
    base++;

//diffutils-3.6/lib/basename-lgpl.c:63:3
for (len = strlen (name);  1 < len && ISSLASH (name[len - 1]);  len--)
    continue;

//diffutils-3.6/lib/exclude.c:552:8
while (len > 0 && ISSLASH (pattern[len-1]))
    --len;

//diffutils-3.6/lib/filenamecat-lgpl.c:40:3
for (f += FILE_SYSTEM_PREFIX_LEN (f); ISSLASH (*f); f++)
    continue;

//diffutils-3.6/lib/hash.c:433:3
for (; (ch = *string); string++)
    value = (value * 31 + ch) % n_buckets;

//bash-4.4/shell.c:1948:7
while (*++s == '-') 
  ;

//bash-4.4/general.c:114:3
  for ( ; s && *s && DIGIT (*s); s++)
    ret = (ret * 10) + TODIGIT (*s);

//bash-4.4/general.c:107:3
while (s && *s && whitespace (*s))
    s++;

//bash-4.4/general.c:161:3
  for (s = string; *s; s++)
    if (DIGIT (*s) == 0)
      return (0);

//bash-4.4/general.c:575:3
  for (i = 0; i < sample_len; i++)
    {
      c = sample[i];
      if (c == '\n')
  return (0);
      if (c == '\0')
  return (1);
    }

//bash-4.4/general.c:1029:3
for (r = s; TILDE_END(*r) == 0; r++)
{
      switch (*r)
  {
  case '\\':
  case '\'':
  case '"':
    return 0;
  }
}

//bash-4.4/general.c:834:3
for (ndirs = 0, ntail = nbeg; *ntail; ntail++)
    if (*ntail == '/')
      ndirs++;

//bash-4.4/general.c:825:5 
for (nbeg = name; *nbeg; nbeg++)
      if (*nbeg == '/')

//bash-4.4/general.c:1055:3
  for (r = s; *r && *r != '/'; r++)
    {
      /* Short-circuit immediately if we see a quote character.  Even though
   POSIX says that `the first unquoted slash' (or `:') terminates the
   tilde-prefix, in practice, any quoted portion of the tilde prefix
   will cause it to not be expanded. */
      if (*r == '\\' || *r == '\'' || *r == '"')
  {
    ret = savestring (s);
    if (lenp)
      *lenp = 0;
    return ret;
  }
      else if (flags && *r == ':')
  break;
    }

//bash-4.4/expr.c:410:3 
for (p = expr; p && *p && cr_whitespace (*p); p++)
    ;

//bash-4.4/expr.c:1376:4
while (xp && *xp && cr_whitespace (*xp))
      xp++;

//bash-4.4/expr.c:1240:3
while (cp && (c = *cp) && (cr_whitespace (c)))
    cp++;


//bash-4.4/expr.c:1417:3
for (t = expression; whitespace (*t); t++)
    ;

//bash-4.4/subst.c:3857:3
for (skip_ctlesc = skip_ctlnul = 0, s = ifs_value; s && *s; s++)
    skip_ctlesc |= *s == CTLESC, skip_ctlnul |= *s == CTLNUL;

//bash-4.4/subst.c:2727:3
for (xflags = 0, s = ifs_value; s && *s; s++)
    {
      if (*s == CTLESC) xflags |= SX_NOCTLESC;
      else if (*s == CTLNUL) xflags |= SX_NOESCCTLNUL;
    }


//bash-4.4/subst.c:2849:3
  for (xflags = 0, s = ifs_value; s && *s; s++)
    {
      if (*s == CTLESC) xflags |= SX_NOCTLESC;
      if (*s == CTLNUL) xflags |= SX_NOESCCTLNUL;
    }



//bash-4.4/subst.c:5938:3
for (skip_ctlesc = skip_ctlnul = 0, s = ifs_value; s && *s; s++)
    skip_ctlesc |= *s == CTLESC, skip_ctlnul |= *s == CTLNUL;

//bash-4.4/subst.c:4494:4
while (pp >= pat && *pp-- == '\\')
      unescaped_backslash = 1 - unescaped_backslash;

//bash-4.4/hashlib.c:141:3
  for (i = 0; *s; s++)
    {
      i *= 16777619;
      i ^= *s;
    }

//bash-4.4/mailcheck.c:328:3
for (s = str, pass_next = 0; s && *s; s++)
{
      if (pass_next)
  {
    pass_next = 0;
    continue;
  }
      if (*s == '\\')
  {
    pass_next++;
    continue;
  }
      if (*s == '?' || *s == '%')
  return s;
}

//bash-4.4/bashhist.c:607:3 
for (p = line; p && *p && whitespace (*p); p++)
    ;

//bash-4.4/bashhist.c:883:3
for (p = s; p && *p; p++)
{
      if (*p == '\\')
  p++;
      else if (*p == '&')
  return 1;
}

//bash-4.4/bashline.c:4200:3
  for (passc = 0; c = string[i]; i++) 
    {    
      if (passc)
  {
    passc = 0; 
    continue;
  }
      if (c == '\\')
  {
    passc++;
    continue;
  }
      if (c == delim)
  break;
    } 

//bash-4.4/locale.c:431:3 
  for (len = 0, s = string; s && *s; s++)
    {
      len++;
      if (*s == '"' || *s == '\\')
  len++;
      else if (*s == '\n')
  len += 5;
    }

//bash-4.4/pcomplete.c:260:3
  for (p = s; p && *p; p++)
    {
      if (*p == '\\')
  p++;
      else if (*p == '&')
  return 1;
    }

//bash-4.4/builtins/common.c:542:3
  while (*string && ISOCTAL (*string))
    {   
      digits++;
      result = (result * 8) + (*string++ - '0');
      if (result > 0777)
  return -1; 
    }   

//bash-4.4/builtins/printf.def:866:2
 for (temp = 2 + (!evalue && !!sawc); ISOCTAL (*p) && temp--; p++)
    evalue = (evalue * 8) + OCTVALUE (*p);

//bash-4.4/builtins/printf.def:768:4
while (DIGIT (*fmt))
      mpr = (mpr * 10) + (*fmt++ - '0');

//bash-4.4/builtins/printf.def:750:7
while (DIGIT (*fmt))
  mfw = (mfw * 10) + (*fmt++ - '0');

//bash-4.4/lib/glob/sm_loop.c:242:8
while (n < se && *n != L('/'))
    ++n;

//bash-4.4/lib/sh/shquote.c:377:3
  for (s = string; s && *s; s++)
    {
      if (*s == '\'' || *s == '"' || *s == '\\')
  return 1;
    }

//bash-4.4/lib/sh/uconvert.c:86:3
  for ( ; p && *p; p++)
    {
      if (*p == DECIMAL)    /* decimal point */
  break;
      if (DIGIT(*p) == 0)
  RETURN(0);
      ipart = (ipart * 10) + (*p - '0');
    }

//bash-4.4/lib/readline/complete.c:739:7
for (x = temp - 1; x > pathname; x--)
  if (*x == '/')
    break;

//bash-4.4/lib/readline/bind.c:1366:4
    e = value + strlen (value) - 1;
    while (e >= value && whitespace (*e))
      e--;

//bash-4.4/lib/readline/bind.c:1358:7
while (*value && whitespace (*value)) value++;

//bash-4.4/lib/readline/bind.c:1355:7
while (*value && whitespace (*value) == 0) value++;

//bash-4.4/lib/readline/bind.c:1351:7
while (*var && whitespace (*var)) var++;

//bash-4.4/lib/readline/bind.c:1329:3
for (; (c = string[i]) && c != ':' && c != ' ' && c != '\t'; i++ );

//bash-4.4/lib/readline/bind.c:1293:3
while (string && whitespace (*string))
    string++;

//bash-4.4/lib/readline/bind.c:1258:3
  for (i = start,passc = 0; c = string[i]; i++)
    {
      if (passc)
  {
    passc = 0;
    if (c == 0)
      break;
    continue;
  }

      if (c == '\\')
  {
    passc = 1;
    continue;
  }

      if (c == delim)
  break;
    }

//bash-4.4/lib/readline/display.c:1536:3
for (nd = nfd - new, ne = nfd; nd < nmax && *ne; ne++, nd++);

//bash-4.4/lib/readline/display.c:1535:3
for (od = ofd - old, oe = ofd; od < omax && *oe; oe++, od++);

//bash-4.4/lib/readline/histexpand.c:342:3
  for (p = s; p && *p; p++, len++)
    {
      if (*p == '\'')
  len += 3;
      else if (whitespace (*p) || *p == '\n')
  len += 2;
    }

//bash-4.4/lib/malloc/malloc.c:778:3
while (busy[nunits]) nunits++;

//bash-4.4/lib/malloc/malloc.c:470:3 
while (nbuck >= SPLIT_MIN && busy[nbuck])
	nbuck--;

//openssh-7.4p1/ssh.c:416:2
  ndots = 0; 
  for (cp = *hostp; *cp != '\0'; cp++) {
    if (*cp == '.') 
      ndots++;
  }

//openssh-7.4p1/readconf.c:2103:3
/* find matching ']' */
for (ep = cp + 1; *ep != ']' && *ep != '\0'; ep++) {
  if (*ep == '/')
    ispath = 1;
}

//openssh-7.4p1/sshkey.c:1294:4
while (*space == ' ' || *space == '\t')
  space++

//openssh-7.4p1/sshbuf-getput-basic.c:413:2
/* Skip leading zero bytes */
for (; len > 0 && *s == 0; len--, s++)
    ;

//openssh-7.4p1/channels.c:1146:2
for (found = 0, i = len; i < have; i++) {
  if (p[i] == '\0') {
    found++;
    if (found == need)
      break;
  }
  if (i > 1024) {
    /* the peer is probably sending garbage */
    debug("channel %d: decode socks4: too long",
        c->self);
    return -1;
  }
}

//openssh-7.4p1/channels.c:1257:3
for (found = 0, i = 2; i < nmethods + 2; i++) {
  if (p[i] == SSH_SOCKS5_NOAUTH) {
    found = 1;
    break;
  }
}

//openssh-7.4p1/misc.c:70:2
while (*t) {
  if (*t == '\n' || *t == '\r') {
    *t = '\0';
    return s;
  }
  t++;
}

//openssh-7.4p1/openbsd-compat/blowfish.c:413:2
for (i = 0; i < 4; i++, j++) {
  if (j >= databytes)
    j = 0;
  temp = (temp << 8) | data[j];
}

//openssh-7.4p1/openbsd-compat/fmt_scaled.c:88:2
  while (*p == '-' || *p == '+') {
    if (*p == '-') {
      if (sign) {
        errno = EINVAL;
        return -1;
      }
      sign = -1;
      ++p;
    } else if (*p == '+') {
      if (sign) {
        errno = EINVAL;
        return -1;
      }
      sign = +1;
      ++p;
    }
  }

//openssh-7.4p1/openbsd-compat/mktemp.c:64:2
for (start = ep; start > path && start[-1] == 'X'; start--) {
  if (tries < INT_MAX / NUM_CHARS)
    tries *= NUM_CHARS;
}

//openssh-7.4p1/openbsd-compat/strlcat.c:43:2
while (n-- != 0 && *d != '\0')
    d++;

//openssh-7.4p1/openbsd-compat/strlcpy.c:51:3
while (*s++)
      ;

//git-2.18.0/builtin/clone.c:239:3
while (start < end && is_dir_sep(end[-1]))
      end--;

//git-2.18.0/builtin/clone.c:226:2
for (ptr = start; ptr < end && !is_dir_sep(*ptr); ptr++) {
  if (*ptr == '@')
    start = ptr + 1;
}

//git-2.18.0/builtin/clone.c:315:2
while (dir < end - 1 && is_dir_sep(end[-1]))
    end--;

//git-2.18.0/builtin/commit.c:628:2
for (p = candidates; *p == ' '; p++)
    ;

//git-2.18.0/builtin/fetch.c:978:2
for (i = url_len - 1; url[i] == '/' && 0 <= i; i--)
    ;

//git-2.18.0/builtin/log.c:726:2
while (len && value[len - 1] == '\n')
    len--;

//git-2.18.0/builtin/mailsplit.c:24:2
  for (;;) {
    if (colon < line)
      return 0;
    if (*--colon == ':')
      break;
  }

//git-2.18.0/builtin/merge.c:479:2
  for (len = 0, ptr = remote + strlen(remote);
       remote < ptr && ptr[-1] == '^';
       ptr--)
    len++;

//git-2.18.0/builtin/pack-objects.c:1480:4
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

//git-2.18.0/builtin/show-branch.c:311:2
  for (p = s, ver = 0;
       '0' <= (ch = *p) && ch <= '9';
       p++)
    ver = ver * 10 + ch - '0';


//git-2.18.0/builtin/worktree.c:204:2
  for (name = path + len - 1; name > path; name--)
    if (is_dir_sep(*name)) {
      name++;
      break;
    }

//git-2.18.0/builtin/worktree.c:201:2
while (len && is_dir_sep(path[len - 1]))
    len--;

//git-2.18.0/abspath.c:43:2
for (end = start; *end && !is_dir_sep(*end); end++)
    ; /* nothing */

//git-2.18.0/abspath.c:40:2
for (start = remaining->buf; is_dir_sep(*start); start++)
    ; /* nothing */

//git-2.18.0/apply.c:420:2
while (size--) {
  len++;
  if (*buffer++ == '\n')
    break;
}

//git-2.18.0/apply.c:602:2
  while (p != line) {
    p--;
    if (*p != ' ')
      return line + len - (p + 1);
  }

//git-2.18.0/apply.c:1142:2
  for (i = 0; i < llen; i++) {
    int ch = line[i];
    if (ch == '/' && --nslash <= 0)
      return (i == 0) ? NULL : &line[i + 1];
  }


//git-2.18.0/archive-tar.c:193:2
  do {
    i--;
  } while (i > 0 && path[i] != '/');

//git-2.18.0/archive-tar.c:181:2
while (p < (const unsigned char *)header + sizeof(struct ustar_header))
    chksum += *p++;

//git-2.18.0/archive-tar.c:177:2
while (p < (const unsigned char *)header->chksum)
    chksum += *p++;

//git-2.18.0/archive-zip.c:257:2
  for (;;) {
    int c = *s++;
    if (c == '\0')
      return 1;
    if (!isascii(c))
      return 0;
  }

//git-2.18.0/attr.c:203:2
  while (namelen--) {
    char ch = *name++;
    if (! (ch == '-' || ch == '.' || ch == '_' ||
           ('0' <= ch && ch <= '9') ||
           ('a' <= ch && ch <= 'z') ||
           ('A' <= ch && ch <= 'Z')) )
      return 0;
  }

//git-2.18.0/combine-diff.c:1213:3
for (i = 0; i < num_parent; i++)
      putchar(p->parent[i].status);

//git-2.18.0/combine-diff.c:930:3
    for (i = 0; added && i < num_parent; i++)
      if (elem->parent[i].status !=
          DIFF_STATUS_ADDED)
        added = 0;

//git-2.18.0/commit.c:91:2
while (buf < tail && *buf++ != '\n')
    /* nada */;

//git-2.18.0/commit.c:86:2
  while (buf < tail && *buf++ != '>')
    /* nada */;

//git-2.18.0/commit.c:80:2
  while (buf < tail && *buf++ != '\n')
    /* nada */;

//git-2.18.0/config.c:607:2
  do {
    if (c == '\n')
      goto error_incomplete_line;
    c = get_next_char();
  } while (isspace(c));

//git-2.18.0/credential.c:365:2
while (*slash == '/')
    slash++;

//git-2.18.0/diff.c:4472:3
    for (i = 0; (optch = optarg[i]) != '\0'; i++) {
      if (optch < 'a' || 'z' < optch)
        continue;
      opt->filter = (1 << (ARRAY_SIZE(diff_status_letters) - 1)) - 1;
      opt->filter &= ~filter_bit[DIFF_STATUS_FILTER_AON];
      break;
    }

//git-2.18.0/diff.c:4857:2
  for (;;) {
    ch = *cp;
    if ( !dot && ch == '.' ) {
      scale = 1;
      dot = 1;
    } else if ( ch == '%' ) {
      scale = dot ? scale*100 : 100;
      cp++; /* % is always at the end */
      break;
    } else if ( ch >= '0' && ch <= '9' ) {
      if ( scale < 100000 ) {
        scale *= 10;
        num = (num*10) + (ch-'0');
      }
    } else {
      break;
    }
    cp++;
  }

//git-2.18.0/diff.c:1319:2
  for (cp = ep; ep - line < len; ep++)
    if (*ep != ' ' && *ep != '\t')
      break;

//git-2.18.0/diff.c:485:2
  while (0 < size--) {
    ch = *data++;
    if (ch == '\n') {
      count++;
      nl_just_seen = 1;
      completely_empty = 0;
    }
    else {
      nl_just_seen = 0;
      completely_empty = 0;
    }
  }

//git-2.18.0/diff.c:2827:2
  for (cnt = 1; cnt < marker_size; cnt++)
    if (line[cnt] != firstchar)
      return 0;

//git-2.18.0/dir.c:61:2
  while (*s)
    if (*s++ == '/')
      cnt++;

//git-2.18.0/dir.c:2069:2
while (len && path[len - 1] == '/')
    len--;

//git-2.18.0/dir.c:608:2
  for (i = 0; i < len; i++) {
    if (p[i] == '/')
      break;
  }

//git-2.18.0/dir.c:215:2
  while (cp < cpe) {
    if (*cp++ != '/')
      continue;
    depth++;
    if (depth > max_depth)
      return 0;
  }


//git-2.18.0/entry.c:392:2
  while (path < slash && *slash != '/')
    slash--;

//git-2.18.0/ewah/ewah_bitmap.c:705:2
  while (size--)
    crc = (crc << 5) - crc + (uint32_t)*p++;

//git-2.18.0/grep.c:1619:2
  for (sp = bol; sp < last_bol; sp++) {
    if (*sp == '\n')
      lno++;
  }

//git-2.18.0/grep.c:1615:2
  for (sp = bol + earliest; bol < sp && sp[-1] != '\n'; sp--)
    ; /* find the beginning of the line */

//git-2.18.0/grep.c:1072:2
  while (l && *cp != '\n') {
    l--;
    cp++;
  }

//git-2.18.0/grep.c:1148:2
  while (bol < --eol) {
    if (*eol != '>')
      continue;
    *eol_p = ++eol;
    ch = *eol;
    *eol = '\0';
    return ch;
  }

//git-2.18.0/hashmap.c:13:2
  while ((c = (unsigned char) *str++))
    hash = (hash * FNV32_PRIME) ^ c;

//git-2.18.0/hashmap.c:21:2
  while ((c = (unsigned char) *str++)) {
    if (c >= 'a' && c <= 'z')
      c -= 'a' - 'A';
    hash = (hash * FNV32_PRIME) ^ c;
  }

//git-2.18.0/hashmap.c:33:2
  while (len--) {
    unsigned int c = *ucbuf++;
    hash = (hash * FNV32_PRIME) ^ c;
  }

//git-2.18.0/hashmap.c:44:2
  while (len--) {
    unsigned int c = *ucbuf++;
    if (c >= 'a' && c <= 'z')
      c -= 'a' - 'A';
    hash = (hash * FNV32_PRIME) ^ c;
  }

//git-2.18.0/hashmap.c:61:2
  while (len--) {
    unsigned int c = *ucbuf++;
    if (c >= 'a' && c <= 'z')
      c -= 'a' - 'A';
    hash = (hash * FNV32_PRIME) ^ c;
  }

//git-2.18.0/ident.c:310:2
  for (cp = line + len - 1; *cp != '>'; cp--)
    ;

//git-2.18.0/ident.c:291:2
  for (cp = split->mail_begin; cp < line + len; cp++)
    if (*cp == '>') {
      split->mail_end = cp;
      break;
    }

//git-2.18.0/ident.c:273:2
  for (cp = line; *cp && cp < line + len; cp++)
    if (*cp == '<') {
      split->mail_begin = cp + 1;
      break;
    }

//git-2.18.0/ident.c:207:2 
  for (; *str; str++) {
    if (!crud(*str))
      return 1;
  }

//git-2.18.0/ident.c:232:2
  while (len > 0) {
    c = src[len-1];
    if (!crud(c))
      break;
    --len;
  }

//git-2.18.0/ident.c:224:2
  while ((c = *src) != 0) {
    if (!crud(c))
      break;
    src++;
  }

//git-2.18.0/mailinfo.c:854:2
  while ((ch = *cp++)) {
    if (ch == ':')
      return 1;
    if ((33 <= ch && ch <= 57) ||
        (59 <= ch && ch <= 126))
      continue;
    break;
  }

//git-2.18.0/name-hash.c:60:2
  while (namelen > 0 && !is_dir_sep(ce->name[namelen - 1]))
    namelen--;

//git-2.18.0/packfile.c:935:2
  while (c & 0x80) {
    if (len <= used || bitsizeof(long) <= shift) {
      error("bad object header");
      size = used = 0;
      break;
    }
    c = buf[used++];
    size += (c & 0x7f) << shift;
    shift += 7;
  }

/* This is detected twice by the loop finder so we count it twice*/
//git-2.18.0/delta.h:95:2
//git-2.18.0/delta.h:95:2
  do {
    cmd = *data++;
    size |= (cmd & 0x7f) << i;
    i += 7;
  } while (cmd & 0x80 && data < top);

//git-2.18.0/packfile.c:1059:3 
    while (c & 128) {
      base_offset += 1;
      if (!base_offset || MSB(base_offset, 7))
        return 0;  /* overflow */
      c = base_info[used++];
      base_offset = (base_offset << 7) + (c & 127);
    }

//git-2.18.0/path.c:83:2
  while (is_dir_sep(buf[len]))
    len++;

//git-2.18.0/path.c:776:3
    while ((1 < len) && (path[len-1] == '/'))
      len--;

//git-2.18.0/path.c:959:4
      while (is_dir_sep(in[j]))
        j++;

//git-2.18.0/path.c:973:4 
      while (is_dir_sep(prefix[i]))
        i++;

//git-2.18.0/path.c:1044:2 
  while (is_dir_sep(in[j]))
    j++;

//git-2.18.0/path.c:1097:2
  while (is_dir_sep(*src))
    src++;

//git-2.18.0/path.c:1213:2
  while (len && is_dir_sep(path[len - 1]))
    len--;

//git-2.18.0/path.c:1264:2
  while (1) {
    char ch = *p++;
    if (sl) { 
      if (ch == '.')
        ndot++; 
      else if (ch == '/') {
        if (ndot < 3)
          /* reject //, /./ and /../ */
          return -1;
        ndot = 0;
      }
      else if (ch == 0) {
        if (0 < ndot && ndot < 3)
          /* reject /.$ and /..$ */
          return -1;
        return 0;
      }
      else
        sl = ndot = 0;
    }
    else if (ch == 0)
      return 0; 
    else if (ch == '/') {
      sl = 1;
      ndot = 0;
    }
  }

//git-2.18.0/path.c:1299:2
  while (len-- > 0) {
    char c = *(path++);
    if (c != ' ' && c != '.')
      return 0;
  }

//git-2.18.0/path.c:1337:3
    for (;;) {
      char c = name[i++];
      if (!c)
        return 1;
      if (c != ' ' && c != '.')
        return 0;
    }

//git-2.18.0/pretty.c:215:2
  while ((ch = *s++) != '\0') {
    if (non_ascii(ch))
      return 1;
  }

//git-2.18.0/pretty.c:247:2
  for (i = 0; i < len; i++)
    if (is_rfc822_special(s[i]))
      return 1;

//git-2.18.0/pretty.c:193:2
  for (;;) {
    char c = *msg++;
    if (!c)
      break;
    ret++;
    if (c == '\n')
      break;
  }

//git-2.18.0/quote.c:216:3
 for (len = 0; !sq_must_quote(s[len]); len++);
//git-2.18.0/quote.c:218:3
for (len = 0; len < maxlen && !sq_must_quote(s[len]); len++);
//git-2.18.0/read-cache.c:662:3 
    while (namelen && path[namelen-1] == '/')
      namelen--;

//git-2.18.0/read-cache.c:1678:2
  for (ep = cp; *ep; ep++)
    ; /* find the end */

//git-2.18.0/refs.c:626:2
  for (c = refname; *c; c++) {
    if (!isupper(*c) && *c != '-' && *c != '_')
      return 0;
  }

//git-2.18.0/refs.c:1720:2
  while (len && is_dir_sep(submodule[len - 1]))
    len--;

//git-2.18.0/refs/files-backend.c:1893:2
  while (bob < scan && *(--scan) != '\n')
    ; /* keep scanning backwards */

//git-2.18.0/ref-filter.c:1103:2
 while (*buf == '\n')
    buf++;

//git-2.18.0/ref-filter.c:1081:2
  while (*buf == '\n')
    buf++;

//git-2.18.0/ref-filter.c:1262:2
  while (remaining > 0) {
    switch (*start++) {
    case '\0':
      return "";
    case '/':
      remaining--;
      break;
    }
  }

//git-2.18.0/remote.c:479:2
  while (*name)
    if (is_dir_sep(*name++))
      return 0;

//git-2.18.0/rerere.c:379:2
  while (marker_size--)
    if (*buf++ != marker_char)
      return 0;

//git-2.18.0/sequencer.c:3450:4
      while (len && p[len - 1] != '\n')
        len--;

//git-2.18.0/sha1-file.c:1149:3
    for (;;) {
      unsigned long c = *hdr - '0';
      if (c > 9)
        break;
      hdr++;
      size = size * 10 + c;
    }

//git-2.18.0/sha1-file.c:1117:2
  for (;;) {
    char c = *hdr++;
    if (!c)
      return -1;
    if (c == ' ')
      break;
    type_len++;
  }

//git-2.18.0/sha1-name.c:1698:2
  for (cp = name, bracket_depth = 0; *cp; cp++) {
    if (*cp == '{')
      bracket_depth++;
    else if (bracket_depth && *cp == '}')
      bracket_depth--;
    else if (!bracket_depth && *cp == ':')
      break;
  }

//git-2.18.0/sha1-name.c:1053:3
    while (cp < name + len)
      num = num * 10 + *cp++ - '0';

//git-2.18.0/sha1-name.c:1040:2
  for (cp = name + len - 1; name <= cp; cp--) {
    int ch = *cp;
    if ('0' <= ch && ch <= '9')
      continue;
    if (ch == '~' || ch == '^')
      has_suffix = ch;
    break;
  }

//git-2.18.0/sha1-name.c:783:3
    for (i = nth = 0; 0 <= nth && i < reflog_len; i++) {
      char ch = str[at+2+i];
      if ('0' <= ch && ch <= '9')
        nth = nth * 10 + ch - '0';
      else
        nth = -1;
    }

//git-2.18.0/sha1-name.c:641:2
  for (cnt = 0; cnt < len; cnt++) {
    switch (*path++) {
    case '\0':
      break;
    case '/':
      if (slash)
        break;
      slash = 1;
      continue;
    case '.':
      continue;
    default:
      slash = 0;
      continue;
    }
    break;
  }

//git-2.18.0/symlinks.c:299:2
  /* Find last slash inside 'name' */
  while (i < len) {
    if (name[i] == '/')
      last_slash = i;
    i++;
  }

//git-2.18.0/tag.c:109:2
  while (buf < tail && *buf++ != '\n')
    /* nada */;

//git-2.18.0/tag.c:104:2 
  while (buf < tail && *buf++ != '>')
    /* nada */;

//git-2.18.0/trailer.c:780:2
  for (; i >= 0; i--) {
    if (buf[i] == '\n')
      return i + 1;
  }

//git-2.18.0/transport.c:892:3
    while (is_urlschemechar(p == url, *p))
      p++;

//git-2.18.0/tree-walk.c:16:2
  while ((c = *str++) != ' ') {
    if (c < '0' || c > '7')
      return NULL;
    mode = (mode << 3) + (c - '0');
  }

//git-2.18.0/tree-walk.c:900:3
    dirlen = matchlen;
    while (dirlen && match[dirlen - 1] != '/')
      dirlen--;

//git-2.18.0/url.c:24:2
  while (*url && *url != ':') {
    if (!is_urlschemechar(0, *url++))
      return 0;
  } 

//git-2.18.0/urlmatch.c:224:2
  while (colon_ptr > url && *colon_ptr != ':' && *colon_ptr != ']')
    colon_ptr--;

//git-2.18.0/varint.c:9:2
 while (c & 128) {
    val += 1;
    if (!val || MSB(val, 7))
      return 0; /* overflow */
    c = *buf++;
    val = (val << 7) + (c & 127);
  }

//git-2.18.0/ws.c:313:2
  /*
   * Check leading whitespaces (indent)
   */
  for (i = 0; i < len; i++) {
    char ch = src[i];
    if (ch == '\t') {
      last_tab_in_indent = i;
      if ((ws_rule & WS_SPACE_BEFORE_TAB) &&
          0 <= last_space_in_indent)
          need_fix_leading_space = 1;
    } else if (ch == ' ') {
      last_space_in_indent = i;
      if ((ws_rule & WS_INDENT_WITH_NON_TAB) &&
          ws_tab_width(ws_rule) <= i - last_tab_in_indent)
        need_fix_leading_space = 1;
    } else
      break;
  }

//git-2.18.0/xdiff-interface.c:21:2
  while ('0' <= *cp && *cp <= '9') 
    num = num * 10 + *cp++ - '0';

//git-2.18.0/xdiff-interface.c:121:2 
  while (recovered < trimmed)
    if (ap[recovered++] == '\n')
      break;

//git-2.18.0/xdiff/xutils.c:308:2
 for (; ptr < top && *ptr != '\n'; ptr++) {
    ha += (ha << 5);
    ha ^= (unsigned long) *ptr;
  }


//patch-2.7/lib/basename-lgpl.c:63:3
  for (len = strlen (name);  1 < len && ISSLASH (name[len - 1]);  len--)
    continue;

//grep-3.1/lib/basename-lgpl.c:63:3
  for (len = strlen (name);  1 < len && ISSLASH (name[len - 1]);  len--)
    continue;

//m4-1.4.18/lib/regex_internal.c:727:7 
  for (; p >= end; --p)
		  if ((*p & 0xc0) != 0x80)
			{
			  mbstate_t cur_state;
			  wchar_t wc2;
			  Idx mlen = raw + pstr->len - p;
			  unsigned char buf[6];
			  size_t mbclen;

			  const unsigned char *pp = p;
			  if (BE (pstr->trans != NULL, 0))
			    {
			      int i = mlen < 6 ? mlen : 6;
			      while (--i >= 0)
				buf[i] = pstr->trans[p[i]];
			      pp = buf;
			    }
			  /* XXX Don't use mbrtowc, we know which conversion
			     to use (UTF-8 -> UCS4).  */
			  memset (&cur_state, 0, sizeof (cur_state));
			  mbclen = __mbrtowc (&wc2, (const char *) pp, mlen,
					      &cur_state);
			  if (raw + offset - p <= mbclen
			      && mbclen < (size_t) -2)
			    {
			      memset (&pstr->cur_state, '\0',
				      sizeof (mbstate_t));
			      pstr->valid_len = mbclen - (raw + offset - p);
			      wc = wc2;
			    }
			  break;
			}

//make-4.2/read.c:1743:9
   while (*line != '\0' && *line != termin)
     ++line;
