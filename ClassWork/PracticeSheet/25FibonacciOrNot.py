n = int(input())
l = list(map(int, input().split()))

if l[0] != 0 or l[1] != 1:
    print("Not Fiboncci sequence")
else:
    check = False
    for i in range(2, len(l)):
        if l[i] == l[i - 1] + l[i - 2]:
            check = True
        else:
            check = False
            break

    if check:
        print("Fiboncci sequence")
    else:
        print("Not Fiboncci sequence")