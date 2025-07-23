import sys

input = sys.stdin.readline

N, M = map(int, input().split())
map = [list(map(int, input().split())) for _ in range(N)]
dp = [[0] * M for _ in range(N)]
for r in range(N):
    for c in range(M):
        if r > 0:
            dp[r][c] = max(dp[r][c], dp[r - 1][c])
        if c > 0:
            dp[r][c] = max(dp[r][c], dp[r][c - 1])
        dp[r][c] += map[r][c]

print(dp[N - 1][M - 1])
