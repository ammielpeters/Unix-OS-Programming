#!/bin/bash
# Demonstration of If-Else, Nested If-Else, and Case (switch)

echo "Enter a number: "
read num

# Simple if-else
if [ $num -gt 0 ]
then
    echo "Positive number"
else
    echo "Negative or Zero"
fi

# Nested if
if [ $num -gt 0 ]
then
    if [ $((num % 2)) -eq 0 ]
    then
        echo "Positive Even number"
    else
        echo "Positive Odd number"
    fi
fi

# Switch case
echo "Enter a character (a/b/c): "
read ch

case $ch in
    a) echo "You entered A";;
    b) echo "You entered B";;
    c) echo "You entered C";;
    *) echo "Invalid choice";;
esac
