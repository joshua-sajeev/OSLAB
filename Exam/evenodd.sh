#!/bin/bash
read -p "Enter a number" num 
if (( $num % 2 == 0 )) ; then
	echo "Even"
else
	echo "Odd"
fi
read -p "Enter a number" num 
if [ `expr $num % 2` == 0 ] ; then
	echo "Even"
else
	echo "Odd"
fi
