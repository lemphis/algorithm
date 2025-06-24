N = int(input())
S = [input() for _ in range(N)]
M = int(input())
A = [input() for _ in range(M)]

pos = S.index("?")
for word in A:
    is_pass = True
    if pos > 0 and word[0] != S[pos - 1][-1]:
        is_pass = False
    if pos < N - 1 and word[-1] != S[pos + 1][0]:
        is_pass = False
    if is_pass:
        if word not in S:
            print(word)
            break
