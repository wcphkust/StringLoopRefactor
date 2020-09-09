#!/bin/bash
ls *.loopinfo | xargs -L1 ./summarizeLoopInfo.sh | tosheets -c B3 -u --spreadsheet=1l9nFmuBU7I5e_AyQaq0zzJu8P1AIKPWSJC7pg1t02kQ
