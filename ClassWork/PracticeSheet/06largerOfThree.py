l = list(map(int, input().split()))

a, b, c = l[0], l[1], l[2]

if a >= b and a >= c:
    print(a)
elif b >= a and b >= c:
    print(b)
else:
    print(c)

