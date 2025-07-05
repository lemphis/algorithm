import sys

input = sys.stdin.readline
N = int(input())
counsels = [tuple(map(int, input().split())) for _ in range(N)]
dp = [0] * (N + 1)
max_cost = 0
for i in range(N):
    if i > 0:
        dp[i] = max(dp[i], dp[i - 1])
    next = i + counsels[i][0]
    if next <= N:
        dp[next] = max(dp[next], dp[i] + counsels[i][1])
        max_cost = max(max_cost, dp[next])

print(max_cost)
