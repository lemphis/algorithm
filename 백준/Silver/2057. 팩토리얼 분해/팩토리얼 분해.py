N = int(input())
if N == 0:
    print("NO")
    exit()

dp = [1] * 20
for i in range(1, 20):
    dp[i] = dp[i - 1] * i

for i in range(19, -1, -1):
    if N >= dp[i]:
        N -= dp[i]

print("YES" if N == 0 else "NO")
