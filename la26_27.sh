# Write a shell script to download webpage at given url using command(wget)

echo "Enter the URL of the webpage to download: "
read url

wget -O downloaded_page.html "$url"

# Check if wget command was successful
if [ $? -eq 0 ]; then
    echo "Webpage downloaded successfully."
else
    echo "Failed to download webpage. Please check the URL and try again."
fi