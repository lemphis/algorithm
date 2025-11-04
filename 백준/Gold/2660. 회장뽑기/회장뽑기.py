import sys

input = sys.stdin.readline

n = int(input())
graph = [[n] * n for _ in range(n)]
while (members := tuple(map(int, input().split()))) != (-1, -1):
    a, b = map(lambda x: x - 1, members)
    graph[a][b] = 1
    graph[b][a] = 1

dp = [[c for c in r] for r in graph]
for k in range(n):
    for i in range(n):
        for j in range(n):
            if k != i != j:
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])

max_friendship = [max(c for c in row if c < n) for row in dp]
candidate_friendship = min(max_friendship)
candidates = [i for i in range(n) if candidate_friendship == max_friendship[i]]

print(candidate_friendship, len(candidates))
print(*map(lambda x: x + 1, candidates), sep=" ")
