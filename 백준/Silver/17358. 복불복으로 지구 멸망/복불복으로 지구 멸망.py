import sys

input = sys.stdin.readline

DIV = 1_000_000_007

N = int(input())

dp = [0] * 100_001
dp[2] = 1
dp[4] = 3
for i in range(6, N + 1, 2):
    dp[i] = (dp[i - 2] * (i - 1)) % DIV

print(dp[N])
