#!/bin/bash

#Array declaration with elements
heroes=(Batman Ironman Spiderman)

#print contents only with @ operator
echo "using @: ${heroes[@]}"

#print arrays elements with string and * operator
echo "using *: ${heroes[*]}"

#!/bin/bash

#Declaring and initializing an indexed array
fruits=(apple, banana, grape)

#Access the first element
echo "first value: ${fruits[0]}"

#Access the second and last array elements
echo "second value: ${fruits[1]}"
echo "last value: ${fruits[2]}"

#!/bin/bash

#Declaring an indexed array and assigning it with values
fruits=(apple banana grape)

#looping through the elements to print
for elems in ${fruits[@]}
    do
        echo $elems
done

#!/bin/bash

#Declaring and initializing an array
currency=(dollar taka rupee yen pound franc dinar dirham)

#print the second  fifth and last elements
echo "total elements: ${#currency[@]} but printed only below ones:"
echo "${currency[1]}"
echo "${currency[4]}"
echo "${currency[7]}"



#!/bin/bash

#Array creation
cards=(hearts diamonds spades clubs)

#Array length calculation and assigning to a new variable named len
len=${#cards[@]}

#printing array length to the prompt
echo $len


#!/bin/bash

# the array to be deleted
language=(c python Golang java)

#deleting the entire array
#unset language

#printing array elements
echo ${language[@]}

#printing array indices
echo ${!language[@]}


#!/bin/bash

#The main array
distros=(ubuntu kali arch)

#prints array with 3 existing elements
echo "array before appending: ${distros[@]}"

#new value to append
distros+=(redHat)

#Prints array with newly added element redHat
echo "array after appending: ${distros[@]}"


#!/bin/bash

#The primary array
bd_bands=(artcell rockStrata warfaze)

#inserting elements into the array at different positions
bd_bands[4]=vibe
bd_bands[10]=powersurge

# loop through the indices and print elements
for position in ${!bd_bands[@]};
do
echo "band ${bd_bands[$position]} is at index: $position"
echo "array after appending: ${bd_bands[@]}"
echo "${bd_bands[10]}"
done


#!/bin/bash

# the array
brands=(adidas puma nike)

#print array
echo "before removal: ${brands[@]}"

# Deleting nike from the array
unset brands[2]

#printing the array after removal of the element nike
echo "after removal: ${brands[@]}"


#!/bin/bash

#the actual array
food=(pizza burger sandwich hotdog pasta chicken)

#print the array
echo "original elements: ${food[@]}"

#slicing the array
sliced=${food[@]:2:3}

#printing the sliced elements
echo "sliced elements: $sliced"



