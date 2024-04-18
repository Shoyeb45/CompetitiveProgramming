s = input()
t = input()

def isAnagram(s, t):
    i, j = 0, 0
    while i < len(s):
        if s[i] == t[j]:
            i += 1
            j += 1
        else:
            i += 1

    if i == len(t):
        return True
    
    return False

if isAnagram(s, t):
    print("Anagram")
else:
    print("Not Anagram")