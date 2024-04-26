# Write a shell script to find whether given file exist or not in folder or on drive.

#!/bin/bash

# Function to check if a file exists
echo "Enter the name of the file to search: "
read filename
if [ -f "$filename" ]; then
    echo "File $filename exists."
else
    echo "File $filename does not exist."
fi