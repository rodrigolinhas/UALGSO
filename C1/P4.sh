#!/bin/bash
#recebe o ano
#se for divisor de 4 ou 400 => Fevereiro tem 29 dias
#senão => Fevereiro tem 28 dias
if [ $(( $1 % 4 )) -eq 0 ] || [ $(( $1 % 400 )) -eq 0 ];
then
echo "Fevereiro tem 29 dias"
else
echo "Fevereiro tem 28 dias"
fi