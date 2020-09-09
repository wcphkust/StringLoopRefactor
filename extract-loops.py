#!/usr/bin/python3
import re
import sys
import os


prog = """#include <stdio.h>
#include <string.h>
#define N 10

char* loopFunction(char* str) {{
{code}
}}

void driver() {{
    char str[N];
    klee_make_symbolic(str, sizeof(str), "str");

    char *p = loopFunction(str); 
    #ifdef DRIVER
    #include "driver.c"
    #endif

}}

#ifdef MAIN_FUNC
#include "main.c"
#endif
"""

comment_re = re.compile("//([a-z0-9]+).+/(.+)\.[a-z]+:(\d+):\d+")

code = ""
file_name = ""
output_directory = "loopFiles/"
if not os.path.exists(output_directory):
        os.makedirs(output_directory)

for line in sys.stdin:
     m = comment_re.match(line)
     if m:
         #cleanup previous iteration
         if file_name != "":
             with open(output_directory + file_name, "w") as f:
                f.write(prog.format(code=code))

         #setup current one
         file_name =  "{prog_name}_{file_name}_{line_number}.c".format(
            prog_name = m.group(1),
            file_name = m.group(2),
            line_number = m.group(3)
         )
         code =  ""
         line = "// " + line[2:]

#         print(prog_name + " in " + file_name + " line number: " + line_number)

     code += line

with open(output_directory + file_name, "w") as f:
  f.write(prog.format(code=code))
