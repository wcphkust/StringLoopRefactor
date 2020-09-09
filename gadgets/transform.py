#!/usr/bin/python3
import sys
import re

body = ""
char = ""
cnt = 123
for line in sys.stdin:
    define = re.search("#ifdef\s+([A-Z])", line);
    endif = re.search("#endif", line);
    sys.stdout.write(line)
    if char != "":
        body += line
    if define:
        char = define.group(1)
        char = char if char != 'V' else ""
#        print(char)
    if endif and char != "":
        for i in range(2,4):
            print("#ifdef " + char + str(i))
            cnt += 1
            sys.stdout.write(re.sub("case\s[A-Z_]+:","case {}:".format(cnt),body))
        char = ""
        body = ""


