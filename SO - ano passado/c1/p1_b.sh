#!/bin/bash
echo "Introduza a dimensao"
read dimensao
find . -size +$dimensao
