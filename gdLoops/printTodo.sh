#!/bin/bash
rm -f done all
ls | grep .prog | cut -d. -f1 > done
find . -maxdepth 1  -name "*.c" | cut -d/ -f2 | cut -d. -f1 > all
grep -Fvxf done all
