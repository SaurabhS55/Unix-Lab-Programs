# Write a program to display the following pyramid. The number of lines in the pyramid should not be hard-coded. 
# It should be obtained from the user.The pyramid should appear as close to the center of the screen as possible. 
import os
os.system('clear')
n = int(input("Enter a number: "))
for i in range (0,n):
    for j in range(0,n-i-1):
        print(end=" ")
    for j in range(0,n+1):
        print(end=" ")
    for j in range(0,i+1):
        print("*",end="")
    print()