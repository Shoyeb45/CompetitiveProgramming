n = int(input())
m = int(input())

a = []

for i in range(0, n):
    l = list(map(int, input().split()))
    a.append(l)

b = [[0 for i in range(m)] for j in range(n)]

