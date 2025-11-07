import sys

input = sys.stdin.readline

dp = [0] * 31
dp[0] = 1
for i in range(1, 31):
    for j in range(i):
        dp[i] += dp[j] * dp[i - 1 - j]

while (N := int(input())) != 0:
    print(dp[N])
