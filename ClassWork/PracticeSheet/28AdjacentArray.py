n = int(input())
l = list(map(int, input().split()))

for i in range(0, len(l) - 1):
    print(l[i] + l[i+1], end = " ")
