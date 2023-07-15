#!/bin/sh
cc -Wall -Wextra -Werror -o rush-01 checkers.c heap_permutuations.c helpers.c main.c

echo "1 2 3 3 3 3 1 2 1 2 2 2 4 3 1 2 "
./rush-01 "1 2 3 3 3 3 1 2 1 2 2 2 4 3 1 2"

echo "\n4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"

echo "\n 2 3 2 1 2 1 2 3 3 1 3 2 1 3 2 3"
./rush-01 "2 3 2 1 2 1 2 3 3 1 3 2 1 3 2 3"

echo "\n 2 3 2 1 2 1 2 3 3 1 3 2 1 3 2 3"
./rush-01 "2 3 2 1 2 1 2 3 3 1 3 2 1 3 2 3"

echo "\n 2 3 2 1 2 1 2 3 3 1 3 2 1 3 2 4"
./rush-01 "2 3 2 1 2 1 2 3 3 1 3 2 1 3 2 4"