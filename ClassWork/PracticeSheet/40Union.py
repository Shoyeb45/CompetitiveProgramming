l1 = list(map(int, input().split()))
l2 = list(map(int, input().split()))

newL = l1
for i in l2:
    if i not in newL:
        newL.append(i)
print(newL)