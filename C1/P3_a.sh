#!/bin/bash
read -p "Extensao original " org
read -p "Extensao nova " nova
for file in *.$org
do
mv -- "$file" "${file%.$org}.$nova"
done