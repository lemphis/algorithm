N = int(input())
dp = [True] * 1_001
dp[1] = False
dp[3] = False
for i in range(5, N + 1):
    dp[i] = not (dp[i - 4] & dp[i - 3] & dp[i - 1])

print("SK" if dp[N] else "CY")
