#!/bin/bash
read -p "Enter limit: " limit 
num1=0
num2=1

for ((i=0;i<limit;i++))do
	echo -n "$num1 "
	sum=$((num1+num2))
	num1=$num2
	num2=$sum
done

