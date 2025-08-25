import sys
from collections import deque

input = sys.stdin.readline

N, M, R = map(int, input().split())
adj = [[] for _ in range(N)]
for i in range(M):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    adj[u].append(v)
    adj[v].append(u)

visited = [False] * N
node_depth = [-1] * N
dq = deque()
dq.append((R - 1, 0))
visited[R - 1] = True
while dq:
    node, depth = dq.popleft()
    node_depth[node] = depth
    for next in adj[node]:
        if not visited[next]:
            dq.append((next, depth + 1))
            visited[next] = True

print(*node_depth, sep="\n")
