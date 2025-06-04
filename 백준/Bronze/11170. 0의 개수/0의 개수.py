dp = [0] * 1_000_001
for i in range(1_000_001):
    dp[i] = str(i).count("0")

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    print(sum(dp[N : M + 1]))
