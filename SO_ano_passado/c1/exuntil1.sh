#!/bin/bash
let "i = 1"
until [ $i -gt 20 ]
do
	echo "$i"
	let "i = i + 1"
done
