#!/bin/bash

# Prompt for user input
read -p "Enter a number: " number

# Initialize the factorial variable to 1
factorial=1

# Calculate the factorial
for ((i=1; i<=number; i++))
do
    factorial=$((factorial * i))
done

# Output the factorial
echo "The factorial of $number is: $factorial"

