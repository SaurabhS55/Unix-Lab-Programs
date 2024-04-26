# Write a program to print “Hello World” message in bold, blink effect, and in different colors like red, blue etc

#!/bin/bash
# ANSI escape codes for formatting
BOLD='\033[1m'
BLINK='\033[5m'
RESET='\033[0m'
# Colors
RED='\033[31m'
BROWN='\033[33m'
# Print "Hello World" with formatting
echo -e "${BOLD}${BLINK}${RED}Hello World${RESET}"
# Print another message with different formatting
echo -e "${BOLD}${BROWN}This is a shell script with different formatting.${RESET}" explain this code

