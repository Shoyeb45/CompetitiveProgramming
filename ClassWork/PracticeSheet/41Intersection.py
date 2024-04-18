l1 = list(map(int, input().split()))
l2 = list(map(int, input().split()))

newL = []
for i in l2:
    if i in l1:
        newL.append(i)
print(newL)