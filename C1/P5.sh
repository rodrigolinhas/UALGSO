#!/bin/bash
inicial= "pwd"
for dir in /bin /etc
do
cd $dir
pwd
ls bash*
sleep 2
done
cd $inicial