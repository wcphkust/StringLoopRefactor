#!/bin/bash
grep summary *.native.run | grep -v prog  | sed 's/.native.run:summary//g' | tosheets -c B3 -s 'Native Run' -u --spreadsheet=1l9nFmuBU7I5e_AyQaq0zzJu8P1AIKPWSJC7pg1t02kQ
