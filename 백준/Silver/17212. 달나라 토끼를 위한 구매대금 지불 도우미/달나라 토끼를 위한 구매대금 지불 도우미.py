import sys

input = sys.stdin.readline

N = int(input())

dp = [0] * 100_001
dp[1] = dp[2] = dp[5] = dp[7] = 1
dp[3] = dp[4] = dp[6] = 2
for i in range(8, 100_001):
    dp[i] = min(dp[i - 1], dp[i - 2], dp[i - 5], dp[i - 7]) + 1

print(dp[N])
