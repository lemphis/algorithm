import sys

input = sys.stdin.readline

N = int(input())

dp = [[0] * 3 for _ in range(N + 1)]
dp[0][0] = 1
for i in range(N - 1):
    for r in range(3):
        dp[i + 1][(r + 1) % 3] = (dp[i + 1][(r + 1) % 3] + dp[i][r]) % 1_000_000_007
        dp[i + 1][(r + 2) % 3] = (dp[i + 1][(r + 2) % 3] + dp[i][r]) % 1_000_000_007

print(dp[N - 1][1])
