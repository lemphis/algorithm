import sys

input = sys.stdin.readline

MAX = 100_001
DIV = 1_000_000_009

dp = [[0] * 3 for _ in range(MAX)]
dp[1][0] = 1
dp[2][1] = 1
dp[3][0] = 1
dp[3][1] = 1
dp[3][2] = 1
for i in range(4, MAX):
    dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % DIV
    dp[i][1] = (dp[i - 2][0] + dp[i - 2][2]) % DIV
    dp[i][2] = (dp[i - 3][0] + dp[i - 3][1]) % DIV

T = int(input())

print(*[sum(dp[int(input())]) % DIV for _ in range(T)], sep="\n")
