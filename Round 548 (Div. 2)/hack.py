x = int(input())
s = str(input()).split()
for  i in range(x):
    s[i] = int(s[i])

s = s[::-1]
sumi = s[0]
for i in range(1, x):
    if s[i-1] > s[i]:
        sumi += s[i]
    else:
        if s[i-1]-1 > 0:
            sumi += s[i-1]-1
            s[i] = s[i-1]-1
        else:
            break
print(sumi)
