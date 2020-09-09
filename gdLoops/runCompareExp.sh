#!/bin/bash

for i in $(seq 4 2 30); do
    OUTPUT_NAME=compare-${i}.cexp
    make comp_clean 
    make comp EXAMPLE_SIZE=$i TIME=240 -j3
    cat *.compare >  ${OUTPUT_NAME}
    sed -i "s/$/ $i/" $OUTPUT_NAME 
done
