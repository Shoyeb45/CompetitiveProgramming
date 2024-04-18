import math
n = int(input())

def sieve(n):
    prime = [True] * (n + 3)
    prime[0] = prime[1] = False

    for i in range(2, int(math.sqrt(n))):
        if prime[i]:
            for j in range(2 * i, n + 1, i):
                prime[j] = False
    
    p = []
    for i in range(2, n + 1):
        if prime[i]:
            p.append(i)

    return p

Prime = sieve(n)

for x in Prime:
    print(x, end=" ")