l1 = list(map(int, input().split()))
l2 = list(map(int, input().split()))

newL = []

for x in l1:
    if x not in l2:
        newL.append(x)
print(newL)