#!/bin/bash
if [ "$2" == "+" ]
then
	let "result = $1 + $3"
fi
if [ "$2" == "x" ]
then
	let "result = $1 * $3"
fi

echo "$result"

#xdg-open to open pdf
