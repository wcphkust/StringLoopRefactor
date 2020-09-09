#!/bin/bash
for dir in *
do
    if [ -d $dir  ]
    then
    PROG_NUMBER=$(ls ${dir} | wc -l)
    echo "${dir} ${PROG_NUMBER}"
    fi
done
