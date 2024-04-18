s = input()
t = input()

def isAnagram(s, t):
    s = ''.join(sorted(s))
    t = ''.join(sorted(t))
    
    if s == t:
        return True

    return False

if isAnagram(s, t):
    print("Anagram")
else:
    print("Not Anagram")