import sys

input = sys.stdin.readline

N = int(input())

dp = [0] * (N + 1)
dp[1] = 1
for i in range(2, N + 1):
    dp[i] = dp[i - 1]
    if i & 1 == 0:
        dp[i] = (dp[i] + dp[i // 2]) % 1_000_000_000

print(dp[N])
