import sys

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    W = input().strip()
    K = int(input())

    pos = [[] for _ in range(26)]
    for i in range(len(W)):
        pos[ord(W[i]) - ord("a")].append(i)

    shortest = float("inf")
    longest = -1
    for i in range(26):
        if len(pos[i]) >= K:
            for j in range(len(pos[i]) - K + 1):
                shortest = min(shortest, pos[i][j + K - 1] - pos[i][j] + 1)
                longest = max(longest, pos[i][j + K - 1] - pos[i][j] + 1)

    if longest > -1:
        print(shortest, longest)
    else:
        print(-1)
