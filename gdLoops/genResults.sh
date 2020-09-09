#!/bin/bash
ls | grep .prog | cut -f1  -d. | xargs -L1 ./showFileAndProg.sh | highlight --syntax=C -O html --inline-css > results.html 
