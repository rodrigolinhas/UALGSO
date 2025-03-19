#!/bin/bash
read -p "Data Inicial (YYYY/MM/DD): " incial
read -p "Data Final (YYYY/MM/DD): " final
find . -type f -newermt $incial ! -newermt $final