import numpy

def matrixMult(a, b):
    n, m = len(a), len(b)
    c = [[0 for i in range(m)] for j in range(n)]

    for i in range(n):
        for j in  range(m):
            for p in range(m):
                c[i][j] = a[i][p] * b[p][j]

    return c
n = int(input())
m = int(input())

a = []

for i in range(0, n):
    l = list(map(int, input().split()))
    a.append(l)
    

x = int(input())
y = int(input())

b = []

for i in range(0, x):
    l = list(map(int, input().split()))
    b.append(l)


if m != x:
    print("Matrix multiplication is not possible")
else:
    c = matrixMult(a, b)
    print(c)
    


