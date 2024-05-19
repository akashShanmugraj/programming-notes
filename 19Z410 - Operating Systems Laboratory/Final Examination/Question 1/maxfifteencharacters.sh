#!/bin/bash

# Prompt the user for input
echo "Please enter a string (max 15 characters):"

# Read up to 15 characters of input
read -n 15 userInput

# Print the input
echo "You entered: $userInput"