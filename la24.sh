# Write a shell script to show the disk partitions and their size and disk usage i.e free space



# Function to display disk partitions and usage
show_disk_usage() {
    echo "Disk Partitions:"
    echo "===================="

    # Get disk partition information using 'df' command
    df -h | awk '
        NR==1 {
            printf "%25s %10s %10s %10s %10s\n", $1, $2, $3, $4, $5
        }
        NR>1 {
            printf "%25s %10s %10s %10s %10s\n", $6, $2, $3, $4, $5
        }
    '

    echo
}

# Call the function
show_disk_usage