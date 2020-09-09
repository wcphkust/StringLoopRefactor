#!/bin/bash
#Loops in /usr/include are excluded because they are the implemntation of string functions
UTILITY_NAME=${1%.loopinfo}
NUM_LOOPS=$(grep loop $1 | grep -v "/usr/include" | wc -l)
NUM_WRITE_LOOPS=$(grep "write loop" $1 | grep -v "/usr/include" | wc -l)
NUM_OUTER_LOOPS=$(grep "Non empty" $1 | grep -v "/usr/include" | wc -l)
let "NUM_INNER_LOOPS=$NUM_LOOPS - $NUM_OUTER_LOOPS"
POINTER_CALLS=$(grep "pointer call" $1 | grep -v "/usr/include" | wc -l)
FOUND_LOOPS=$(grep "BINGO!" $1 | grep -v "/usr/include" | wc -l)

echo "$UTILITY_NAME   $NUM_LOOPS   $NUM_INNER_LOOPS   $POINTER_CALLS   $NUM_WRITE_LOOPS  $FOUND_LOOPS"

# sed  -n 's@^//\([^/]\+\)/\(.\+/\)\?\([^/]\+\)\.c:\([0-9]\+\):.*$@\1_\3_\4@p' FoundLoops.c
