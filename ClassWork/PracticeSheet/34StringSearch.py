l = list(map(str,input().split()))
s = input()
def checkString(l, s):
    for str in l:
        if str == s:
            print("String present")
            return
    
    print("String not present")

checkString(l, s)
    