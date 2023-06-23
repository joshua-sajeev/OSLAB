#!/bin/bash

# Using a for loop
for ((i=1; i<=5; i++))
do
    echo "Welcome --> FOR"
done
# Using a while loop
i=1
while [ $i -le 5 ]
do
    echo "Welcome --> WHILE"
    i="expr $i + 1"
done
