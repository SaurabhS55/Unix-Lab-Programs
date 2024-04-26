# Write a shell script to find the given file in the system using find or locate command.

#!/bin/bash

# Function to find a file using the 'find' command
echo "Enter the name of the file to search: "
read filename

# Search for the file using the 'find' command
find / -name "$filename" 2>/dev/null