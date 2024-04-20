# Write a python recursive function for prime number input limit in as parameter to it.

def isPrime(n,i,sq):
    if i>sq:
        return True
    if n%i==0:
        return False
    return isPrime(n,i+1,sq)

def prime(n):
    if n<2:
        return False
    return isPrime(n,2,n**0.5)

n = int(input("Enter a number: "))
if prime(n):
    print(n,"is a prime number")
else:
    print(n,"is not a prime number")