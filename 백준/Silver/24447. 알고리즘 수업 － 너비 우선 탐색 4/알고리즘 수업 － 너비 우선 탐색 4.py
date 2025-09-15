import sys
from collections import deque

input = sys.stdin.readline

N, M, R = map(int, input().split())
adj = [list() for _ in range(N + 1)]
for _ in range(M):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

for i in range(1, N + 1):
    adj[i].sort()

node_depth = [-1] * (N + 1)
node_order = [0] * (N + 1)
node_depth[R] = 0
dq = deque([(R, 0)])
node_order[R] = order = 1
while dq:
    node, depth = dq.popleft()
    for next in adj[node]:
        if node_depth[next] < 0:
            dq.append((next, depth + 1))
            node_depth[next] = depth + 1
            order += 1
            node_order[next] = order

print(sum(node_depth[i] * node_order[i] for i in range(1, N + 1)))
