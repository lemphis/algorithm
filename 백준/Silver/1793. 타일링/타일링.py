import sys

input = sys.stdin.readline

dp = [0] * 251
dp[0] = dp[1] = 1

for i in range(2, 251):
    dp[i] = dp[i - 2] * 2 + dp[i - 1]

ans = []
while line := input():
    ans.append(dp[int(line)])

print(*ans, sep="\n")
