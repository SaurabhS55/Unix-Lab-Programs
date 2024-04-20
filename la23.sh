# Write a shell script to find whether given file exist or not in folder or on drive.

#!/bin/bash

# Function to check if a file exists
check_file_exists() {
    local file_path="$1"
    
    if [ -f "$file_path" ]; then
        echo "File '$file_path' exists."
    else
        echo "File '$file_path' does not exist."
    fi
}

# Prompt user for file path
read -p "Enter the file path (e.g., /path/to/file.txt or /path/to/folder/): " file_path

# Check if the file exists
check_file_exists "$file_path"