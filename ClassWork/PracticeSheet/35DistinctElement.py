n = int(input())
l = list(map(int, input().split()))

def distinct(l):
    newList = []
    for i in range(len(l)):
        if l[i] not in l[i + 1:]:
            newList.append(l[i])

    return newList

for x in distinct(l):
    print(x, end = " ")