import numpy
n = int(input())
m = int(input())

a = []

for i in range(0, n):
    l = list(map(int, input().split()))
    a.append(l)

aT = [[j[i] for j in a] for i in range(m)]
a = numpy.array(a)  # for checking
print(aT,"\n",a.T)