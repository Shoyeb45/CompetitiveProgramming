l = list(map(int, input().split()))

def absolute(a, b):
    return a -b if a - b > 0 else -1 * (a - b) 

print(absolute(l[0], l[1]))
