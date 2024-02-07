#!/bin/bash

# Function to calculate the sum of digits
sum_of_digits() {
    num=$1
    sum=0

    while [ $num -gt 0 ]; do
        digit=$((num % 10))
        sum=$((sum + digit))
        num=$((num / 10))
    done

    echo "Sum of digits: $sum"
}

# Read input from user
number=172345

# Call the function
sum_of_digits $number
