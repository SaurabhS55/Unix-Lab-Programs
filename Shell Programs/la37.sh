# Write a shell script to download a given file from ftp://10.10.13.16  if it exists on ftp. (use lftp, get and mget commands)

#!/bin/bash

# FTP server URL
ftp_url="ftp://10.10.13.16"

# File to download
file_name="example.txt"

# Check if the file exists on the FTP server
ftp_exists=$(lftp -c "open '$ftp_url'; cls -1 '$file_name'")

if [ -n "$ftp_exists" ]; then
    # File exists, download it
    lftp -c "open '$ftp_url'; get '$file_name'"
    echo "File '$file_name' downloaded successfully."
else
    echo "Error: File '$file_name' does not exist on the FTP server."
fi
