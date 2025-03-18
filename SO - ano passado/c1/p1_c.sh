#!/bin/bash
echo "Introduza a data de inicio do intervalo"
read data1
echo "Introduza a data de fim do intervalo"
read data2
find -newermt "$data1" ! -newermt "$data2"
