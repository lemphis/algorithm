import sys

input = sys.stdin.readline

N = int(input())
scores = list(map(int, input().split()))

dp = [0] * N

for i in range(N):
    current_max = scores[i]
    current_min = scores[i]

    for j in range(i, -1, -1):
        current_max = max(current_max, scores[j])
        current_min = min(current_min, scores[j])

        cost = current_max - current_min
        dp[i] = max(dp[i], (dp[j - 1] if j > 0 else 0) + cost)

print(dp[N - 1])
