import sys

input = sys.stdin.readline

V, E = map(int, input().split())
edges = [list(map(int, input().split())) for _ in range(E)]

adj = [[float("inf")] * V for _ in range(V)]
for a, b, c in edges:
    adj[a - 1][b - 1] = c

for v in range(V):
    for s in range(V):
        for e in range(V):
            adj[s][e] = min(adj[s][e], adj[s][v] + adj[v][e])

ans = min([adj[i][i] for i in range(V)])
print(-1 if ans == float("inf") else ans)
