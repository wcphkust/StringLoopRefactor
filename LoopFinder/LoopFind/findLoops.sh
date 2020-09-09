#!/bin/bash
OPT=opt
LIB=/artefact/loops/LoopFinder/build/LoopFind/libLLVMLoopFinder.so
${OPT} --load ${LIB} -mem2reg -hello -S -o out.ll < $1 > /dev/null
