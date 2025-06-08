n = int(input())
dp = [0] * 10_001
dp[1] = 1
for i in range(2, 10_001):
    dp[i] = dp[i - 1] + dp[i - 2]

print(dp[n])