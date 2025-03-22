#!/bin/bash
echo "Insira o nome da extensao existente que deseja alterar"
read old
echo "Insira o novo nome da extansao"
read new
for file in *.$old
do
	mv "$file" "${file%.$old}.$new"
done
