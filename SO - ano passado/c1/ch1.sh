#!/bin/bash
start=`pwd`
cd $1
currentfolder=`ls`
array=()

for file in $currentfolder
do
	array+=($file)
done

let "i = ${#array[@]}"
let "n = 0"

while [ $i -gt $n ]
do
	echo "${array[i-1]}"
	let "i = i - 1"
done

cd $start
