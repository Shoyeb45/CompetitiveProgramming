n = int(input())

temp = n
cnt = -1
while(n >= 1):
    cnt += 1
    n = n // 2

if ((2 ** (cnt + 1)) - temp) > (temp - (2 ** (cnt))):
    print(cnt)
else:
    print(cnt + 1)