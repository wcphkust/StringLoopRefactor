#!/bin/bash
ls *.prog | cut -f1 -d. | awk '{print $0".synth"}' | xargs -L1000 klee-stats | cut -d'|' -f2,4 | head -n-3 | tail -n+4 | sed 's/libosip2_osip/libosip2/g' | sed 's/www_/www/g'  |  tosheets -c C4 -u -d '|' -s Synthesized --spreadsheet=1l9nFmuBU7I5e_AyQaq0zzJu8P1AIKPWSJC7pg1t02kQ
