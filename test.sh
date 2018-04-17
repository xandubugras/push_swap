#!/bin/sh
make
./checker 5 10 15
echo "OK\n"

./checker 10 5 15
echo "KO\n"

./checker 
echo "\n"

./checker 5 a 10
echo "Error\n"

