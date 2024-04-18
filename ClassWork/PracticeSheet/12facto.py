x = int(input())

def facto(x):
    if x == 1 or x == 0:
        return 1
    
    return x * facto(x - 1)

print(facto(x))