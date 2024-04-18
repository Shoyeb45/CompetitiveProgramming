l = list(map(int, input().split()))

def swap1(l):
    temp = l[0]
    l[0] = l[1]
    l[1] = temp

def swap2(l):
    l[0] = l[0] + l[1]
    l[1] = l[0] - l[1]
    l[0] = l[0] - l[1]

swap1(l)
print(f"{l[0]} {l[1]}")
swap2(l)
print(f"{l[0]} {l[1]}")