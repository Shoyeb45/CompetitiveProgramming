import math
x = int(input())

def isPrime(x):
    if x == 1:
        return False
    
    i = 2
    while (i <= math.sqrt(x)):
        if(x % i == 0):
            return False
        i = i + 1
        
    return True

print(isPrime(x))