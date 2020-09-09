#!/bin/bash
FILES=compare-*.cexp
cat $FILES | grep -B 2  Error -n | sed -n 's/^\([0-9]\{1,\}\).*/\1d/p' > sed.tmp
cat $FILES | sed -f sed.tmp | tosheets --spreadsheet=1l9nFmuBU7I5e_AyQaq0zzJu8P1AIKPWSJC7pg1t02kQ -s StrCompare -c B2 -u 
rm sed.tmp

