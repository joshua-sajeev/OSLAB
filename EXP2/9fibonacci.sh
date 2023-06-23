#!/bin/bash

# Prompt for user input
read -p "Enter the number of Fibonacci numbers to generate: " count

# Initialize variables
num1=0
num2=1

echo "Fibonacci Series:"

# Generate and display Fibonacci numbers
for ((i=0; i<count; i++))
do
    echo -n "$num1 "

    # Calculate the next Fibonacci number
    nextNum=$((num1 + num2))

    # Update variables for the next iteration
    num1=$num2
    num2=$nextNum
done

echo

