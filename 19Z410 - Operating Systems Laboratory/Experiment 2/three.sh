#!/bin/bash

n=17234
sum=0

for ((i=1; i<=n; i++))
do
  sum=$((sum + i))
done

echo "The sum of the first $n natural numbers is: $sum"
