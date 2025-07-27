import sys

input = sys.stdin.readline

N = int(input())
nums = list(map(int, input().split()))

dp = [[0] * 2 for _ in range(N)]
dp[0][0] = nums[0]
dp[0][1] = -1e9
max_sum = max(dp[0][0], dp[0][1])
for i in range(1, N):
    dp[i][0] = max(dp[i - 1][0] + nums[i], nums[i])
    dp[i][1] = max(dp[i - 1][1] + nums[i], dp[i - 1][0])
    max_sum = max(max_sum, dp[i][0], dp[i][1])

print(max_sum)
