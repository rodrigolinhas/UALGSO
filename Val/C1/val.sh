#!/bin/bash

declare -a fibonacci

#read -p "Quantos fibonacci quer?" fib

fibonacci[0]=0
fibonacci[1]=1

#            $fib
for i in {2..29}; do
    fibonacci[$i]=$(( fibonacci[i-1] + fibonacci[i-2] ))
done

for num in "${fibonacci[@]}"; do
    echo "$num"
done > output.txt

echo "Done"