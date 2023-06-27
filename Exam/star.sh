#!/bin/bash
read -p "Enter number of rows" rows
for((i=0;i<rows;i++))do
	for((j=0;j<=i;j++))do
		echo -n *$'\t'
	done
	echo
done
