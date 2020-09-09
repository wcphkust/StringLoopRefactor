#!/bin/bash
for dir in *.dir
do
    NUMBER=$(echo ${dir}/*.prog | tr ' ' '\n' | wc -l)
    if [ ${dir%.dir} -eq 1 ]
    then
    NUMBER=0
    fi
    PROG_SIZE=${dir%.dir}
    echo "$PROG_SIZE $NUMBER"
done
