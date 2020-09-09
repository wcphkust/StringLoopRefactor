#!/usr/bin/python3
import sys

outline = """#include<string.h>
char *loopFunctionProg(char* s) {{
    char *result = s;
    int condition_flag = 1;
    {}

}}
"""

cond_check = """
  if(condition_flag == 1) {{
      {}
  }} else condition_flag = 1;
"""

MEM_CHR = 'm'
STR_R_CHR = 'r'
STR_CHR = 'c'
STR_SPAN = 'p'
STR_C_SPAN = 'n'
STR_P_BRK = 'b'

IS_NULL = 'z'
IS_START = 'x'
SET_TO_END = 'e'
SET_TO_START = 's'
INC = 'i'
REVERSE = 'v'
END = 'f'

ISDIGIT_METACHAR = '\a'
COMMON_WHITESPACE_METACHAR = '\f'

def esc(s):
  return  s.encode("unicode_escape").decode("ASCII").replace("\"","\\\"")

def getSequence(f):
  c = f.read(1)
  l = []
  while c != 'f':
      if c == ISDIGIT_METACHAR:
        l += list("0123456789")
      elif c == COMMON_WHITESPACE_METACHAR:
        l += list(" \t\n")
      else:
        l += [c]
      c = f.read(1)
  return "".join(l)

def compileOpCode(c, f):
  assert c != 'v', "Reverse unsupported"
  inst = ""


  if c == STR_CHR:
      inst = "result = strchr(result, '{}');".format(esc(f.read(1)))
  elif c == MEM_CHR:
      #we model memchr as strchr, because we have no better way of knowing the length
      #inst = "result = memchr(result, '{}', 4);".format(esc(f.read(1)))
      inst = "result = strchr(result, '{}');".format(esc(f.read(1)))
  elif c == STR_R_CHR:
      inst = "result = strrchr(result, '{}');".format(esc(f.read(1)))
  elif c == STR_P_BRK:
      inst = "result = strpbrk(result, \"{}\");".format(esc(getSequence(f)))
  elif c == STR_SPAN:
      inst = "result = result + strspn(result, \"{}\");".format(esc(getSequence(f)))
  elif c == STR_C_SPAN:
      inst = "result = result + strcspn(result, \"{}\");".format(esc(getSequence(f)))
  elif c == IS_NULL:
      inst = "condition_flag = (result < (char*)0x10);"
  elif c == IS_START:
      inst = "condition_flag = (result == s);"
  elif c == INC:
      inst = "result++;"
  elif c == SET_TO_END:
      inst = "result = s + strlen(s);"
  elif c == SET_TO_START:
      inst = "result = s;"
  elif c == END:
      return "return result;"
  else:
      sys.stderr.write("Unknown character {}\n".format(esc(c)))
      assert False
  
  return cond_check.format(inst)
  
  

def compileProg(filename):
  loc = []
  with open(filename) as f:
    c = f.read(1)
    while c != 'f':
      if not c:
        break
#      sys.stderr.write("looking at {}\n".format(esc(c)))
      loc.append(compileOpCode(c,f))
      c = f.read(1)

    loc.append(compileOpCode(c,f))

  print(outline.format("".join(loc)))


compileProg(sys.argv[1])
