#!/bin/bash
function sum(){
echo "Resposta: "
echo "$(( $int + $int2 ))"
}
echo "SOMA DE 2 INTEIROS"
read -p "1o Inteiro: " int
read -p "2o Interio: " int2
sum $int $int2