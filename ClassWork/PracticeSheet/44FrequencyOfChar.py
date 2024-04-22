s = input()

def occurence(s, c):
    count = 0
    for j in s:
        if ord(j) == c:
            count = count + 1
    print(f"Frequency of {chr(c)} is {count}")
def frequency(s):
    for i in range(0, 26):
        c = ord('a') + i
        occurence(s, c)


frequency(s)