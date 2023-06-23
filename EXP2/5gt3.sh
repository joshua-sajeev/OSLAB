#!/bin/bash
read -p "Enter the first number: " num1
read -p "Enter the second number: " num2
read -p "Enter the third number: " num3
max=$num1
if [ "$num2" -gt "$max" ]; then
    max=$num2
fi

if [ "$num3" -gt "$max" ]; then
    max=$num3
fi

echo "The greatest number is: $max"

