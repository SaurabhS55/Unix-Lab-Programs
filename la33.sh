# Write a shell script that will take a filename as input and check if it is executable

echo "Enter the filename: "
read filename

if [ ! -x "$filename" ]; then
    echo "The file '$filename' does not exist."
    exit 1
fi

if [ -x "$filename" ]; then
    echo "The file '$filename' is executable."
    chmod -x "$filename"
    echo "The file '$filename' is no longer executable."
else
    echo "The file '$filename' is not executable"
fi