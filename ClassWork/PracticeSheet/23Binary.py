def decToBinary(x):
    if x == 0:
        return 0
    
    return ((x % 2) + 10 * decToBinary(x//2))

n = int(input())
print(decToBinary(n))