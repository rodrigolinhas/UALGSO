#!/bin/bash
let "resto = $1 % 4"
if [ $resto -eq 0 ]
then
	echo "Fevereiro tem 29 dias no ano $1"
else
	echo "Fevereiro tem 28 dias no ano $1"
fi
