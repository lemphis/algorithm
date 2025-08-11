import sys

input = sys.stdin.readline

N = int(input())
S = [input().split() for _ in range(N)]
L = input().split()

idxes = [0] * N
for word in L:
    matched = False
    for i in range(N):
        if idxes[i] < len(S[i]) and S[i][idxes[i]] == word:
            idxes[i] += 1
            matched = True
            break
    if not matched:
        print("Impossible")
        exit()

for i in range(N):
    if idxes[i] != len(S[i]):
        print("Impossible")
        break
else:
    print("Possible")
