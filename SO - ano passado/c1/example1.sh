#!/bin/bash
let "i = $1"
let "result = 0"
while [[ $i -gt 0 ]]
do
	let "atual = $i % 2"
	let "result = "${result} ${atual}""
	let "i = i / 2"
done
echo "$result"
