# Write a program to check whether system is in network or not using ’ping’ command using shell script.

target="google.com"

ping -c 5 -q $target

if [ $? -eq 0 ]; then
    echo "System is in network"
else
    echo "System is not in network"
fi