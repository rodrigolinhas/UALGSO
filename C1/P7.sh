#!/bin/bash
inf=1
sup=20
corrente=$inf
until [ $corrente -gt $sup ]; do
echo "Valor corrente: " $corrente
let "corrente = corrente + 1"
done