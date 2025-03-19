#!/bin/bash
#Tenho que usar o cat > output.txt
#depois contar todas as linhas que contem output.txt
read -p "1o ficheiro para juntar (expecifice a extensao tambem): " f1
read -p "2o ficheiro para juntar (expecifici a extensao tambem): " f2
cat $f1 $f2 > f3.txt
echo "O ficheiro novo contem o seguinte numero de linhas:"
wc -l f3.txt