#!/bin/bash
let "i = 1"
while [ $i -le 20 ]
do
	echo "$i"
	let "i = i + 1"
done
