#!/bin/bash
for exp in exp-*
do
    NUM=$(ls $exp/*.prog 2> /dev/null | wc -l)
    echo "$exp $NUM"

done
