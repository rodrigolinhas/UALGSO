#!/bin/bash
let "i = 0"
while [ $i -le $2 ]
do
	let "r = i * $1"
	echo "$i x $1 = $r"
	let "i = i + 1"
done
