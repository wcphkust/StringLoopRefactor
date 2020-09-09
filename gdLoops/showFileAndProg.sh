#!/bin/bash
echo "====== Showing $1 ========"
head -n 20 $1.c
hexdump -c $1.prog
