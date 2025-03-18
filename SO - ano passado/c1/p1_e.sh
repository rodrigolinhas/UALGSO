#!/bin/bash
echo "Introduza o texto que quer encontrar"
read padrao
grep -rw . -e "$padrao"
