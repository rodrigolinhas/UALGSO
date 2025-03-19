#!/bin/bash
num=$1
num2=$2
i=0
while [ $i -le $num2 ]
do
echo "$i * $num = $(($num*i))"
i=$((i+1))
done