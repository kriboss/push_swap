#!/bin/bash

# Usage: ./generate_numbers.sh <file_name> <count> <max_size>

if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <file_name> <count> <max_size>"
    exit 1
fi

file_name=$1
count=$2
max_size=$3

# Generate random numbers and write to file
shuf -i 0-$max_size -n $count | tr '\n' ' ' | sed 's/ $//' > $file_name