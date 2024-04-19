n = int(input())
m = int(input())

A = []
for i in range(n):
    l = list(map(int, input().split()))
    A.append(l)

def sumRow(A):
    sumRow = []
    for i in range(len(A)):
        sumRow.append(sum(A[i]))
    
    return sumRow

for i in sumRow(A):
    print(i, end = " ")
