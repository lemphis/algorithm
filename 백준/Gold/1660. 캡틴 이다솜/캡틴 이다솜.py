import sys

input = sys.stdin.readline

tetra = [0] * 122
for i in range(1, 122):
    tetra[i] += sum(range(i + 1)) + tetra[i - 1]

N = int(input())

dp = [float("inf")] * (N + 1)
dp[0] = 0
for num in tetra[1:]:
    for i in range(num, N + 1):
        dp[i] = min(dp[i], dp[i - num] + 1)

print(dp[N])
