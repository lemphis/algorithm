N = int(input())

dp = [(0, 0)] * 21
dp[1] = (1, 1)
dp[2] = (2, 1)
dp[3] = (4, 2)
for i in range(4, 21):
    dp[i] = (dp[i - 1][0] * 2, dp[i - 1][0])
    if i & 1 == 0:
        dp[i] = (dp[i][0] - dp[i - 3][1] - dp[i - 4][1], dp[i - 1][0])

print(dp[N][0])
