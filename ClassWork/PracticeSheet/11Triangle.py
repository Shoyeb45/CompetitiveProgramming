l = list(map(int, input().split()))

if l[0] + l[1] >= l[2] and l[0] + l[2] >= l[1] and l[2] + l[1] >= l[0]:
    print("Valid sides")
else:    
    print("Not-Valid sides")

