#!/bin/bash

# Prompt for user input
read -p "Enter the first number: " num1
read -p "Enter the second number: " num2
read -p "Enter the third number: " num3

# Initialize the maximum variable with the first number
max=$num1

# Compare the second number with the current maximum
if [ "$num2" -gt "$max" ]; then
    max=$num2
fi

# Compare the third number with the current maximum
if [ "$num3" -gt "$max" ]; then
    max=$num3
fi

# Output the greatest number
echo "The greatest number is: $max"

