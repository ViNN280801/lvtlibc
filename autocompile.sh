#!/bin/bash

gcc -c lvt.c -lm -Wall -Wpedantic -Wextra -std=c18 -o lvt.o
gcc -c main.c -lm -Wall -Wpedantic -Wextra -std=c18 -o main.o
gcc lvt.o main.o -lm -Wall -Wpedantic -Wextra -std=c18 -o main

rm *.o
