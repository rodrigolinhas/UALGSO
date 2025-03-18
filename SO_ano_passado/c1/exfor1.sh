#!/bin/bash
start=`pwd`
for dir in /bin /etc
do
	cd $dir
	pwd
	sleep 2
done
cd $start
