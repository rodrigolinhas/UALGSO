#!/bin/bash
inf=1
sup=20
corrente=$inf
while [ $corrente -le $sup ]
do
echo "Valor corrente: " $corrente
let "corrente = corrente + 1"
done