#!/bin/bash

for i in {1..5}
do
    echo $i
done

#!/bin/bash
for i in {1..5}
do
   echo "Welcome $i times"
done

#!/bin/bash
echo "Bash version ${BASH_VERSION}..."
for i in {0..10..2}
do 
  echo "Welcome $i times"
done

for i in $(seq 1 2 20)
do
   echo "Welcome $i times"
done


# set counter 'c' to 1 and condition 
# c is less than or equal to 5
for (( c=1; c<=5; c++ ))
do  
   echo "Welcome $c times"
done

#!/bin/bash
#for (( ; ; ))
#do
 #  echo "infinite loops [ hit CTRL+C to stop]"
#done

#!/bin/bash
# Count dns name server in the /etc/resolv.conf if found
for file in /etc/*
do
        # check if file exists in bash using the if #  
	if [ "${file}" == "/etc/resolv.conf" ]
	then
		countNameservers=$(grep -c nameserver /etc/resolv.conf)
		echo "Total dns ${countNameservers} nameservers defined in ${file}"
		break
	fi
done
