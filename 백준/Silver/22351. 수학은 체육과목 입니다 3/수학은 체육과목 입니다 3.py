S = input()

s_len = len(S)
for i in range(1, 1000):
    j = i
    l = 0
    r = len(str(j))
    while r <= s_len and S[l:r] == str(j):
        j += 1
        l = r
        r += len(str(j))
    if l == s_len:
        print(i, j - 1)
        break
