#!/bin/bash
gcc sjf.c
cat array.txt | while read line; do
  ./a.out $line
done
gcc fcfs.c
cat array.txt | while read line; do
 ./a.out $line
done
gcc round_robin.c
cat array.txt | while read line; do
 ./a.out $line
done

