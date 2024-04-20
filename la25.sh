# Write a shell script to find the given file in the system using find or locate command.

#!/bin/bash

# Function to find a file using the 'find' command
find_file_with_find() {
    local file_name="$1"

    echo "Searching for '$file_name' using 'find' command..."
    find / -name "$file_name" 2>/dev/null
}

# Prompt user for file name
read -p "Enter the file name to search for: " file_name

# Check if the 'locate' database is available
find_file_with_find "$file_name"
