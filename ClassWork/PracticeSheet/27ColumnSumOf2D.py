n = int(input())
m = int(input())

A = []
for i in range(n):
    l = list(map(int, input().split()))
    A.append(l)

def sumCol(A):
    sumCol = []
    for j in range(len(A[0])):
        sum = 0
        for i in  range(len(A)):
            sum += A[i][j]
        sumCol.append(sum)
    
    return sumCol

for i in sumCol(A):
    print(i, end = " ")
