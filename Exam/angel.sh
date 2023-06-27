#!/bin/bash
read -p "Enter your name: " name
if [ $name = "Angel" ]; then
	echo Yes
else
	echo "No"
fi
