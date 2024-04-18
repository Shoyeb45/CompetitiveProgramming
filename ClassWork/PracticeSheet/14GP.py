def generateGP(a, r, n):
    i = a
    while(i <= a * r**(n-1)):
        print(i)
        i = i * r
    
a = int(input())
r = int(input())
n = int(input())

generateGP(a, r, n)