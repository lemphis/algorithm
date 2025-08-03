N = int(input())
candies = [int(input()) for _ in range(N)]

n0_candy = sum(-a if i & 1 else a for i, a in enumerate(candies)) // 2
ans = [n0_candy]
for i in range(N - 1):
    ans.append(candies[i] - ans[i])

print(*ans, sep="\n")
