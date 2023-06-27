#!/bin/bash
for((i=0;i<5;i++)) do
	echo "WELCOME --> for"
done
i=0
while((i<5)) do
	echo "WELCOME --> while"
	((i++))
done
i=1
while [ $i -le 5 ]; do
	echo "WELCOME --> while"
	i=`expr $i + 1`
done
