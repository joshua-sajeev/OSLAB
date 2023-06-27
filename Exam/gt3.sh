#!/bin/bash
read -p "Enter number 1: " num1
read -p "Enter number 2: " num2
read -p "Enter number 3: " num3
max=$num1

if (( $num2 > $num1 )) then 
	max=$num2
fi 
if (( $num3 > $num1 )) then
	max=$num3
fi
echo "$max is greater"
