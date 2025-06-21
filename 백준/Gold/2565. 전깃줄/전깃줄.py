n = int(input())
line_map = {int(k): int(v) for k, v in (input().split() for _ in range(n))}
dp = [[0] * 501 for _ in range(501)]
for i in range(1, 501):
    for j in range(1, 501):
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        if i in line_map and line_map[i] == j:
            dp[i][j] += 1

print(n - dp[500][500])
