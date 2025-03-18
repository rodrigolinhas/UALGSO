#!/bin/bash
echo "Introduza o numero do qual quer calcular o fatorial"
read n
let "f = n"
while [ $n -gt 2 ]
do
	let "n = n-1"
	let "f = f * n"
done
echo $f
