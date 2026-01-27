import sys

input = sys.stdin.readline

N, M = map(int, input().split())
k = int(input())
s = set()
for _ in range(k):
    a, b, c, d = map(int, input().split())
    s.add(tuple(sorted([(a, b), (c, d)])))

dp = [[0] * (M + 1) for _ in range(N + 1)]
dp[0][0] = 1
for r in range(N + 1):
    for c in range(M + 1):
        if r > 0 and ((r - 1, c), (r, c)) not in s:
            dp[r][c] += dp[r - 1][c]
        if c > 0 and ((r, c - 1), (r, c)) not in s:
            dp[r][c] += dp[r][c - 1]

print(dp[N][M])
