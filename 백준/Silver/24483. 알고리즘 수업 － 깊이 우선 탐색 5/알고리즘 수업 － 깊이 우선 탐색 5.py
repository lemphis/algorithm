import sys

input = sys.stdin.readline

N, M, R = map(int, input().split())
adj = [list() for _ in range(N + 1)]
for _ in range(M):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

for i in range(1, N + 1):
    adj[i].sort(reverse=True)

node_depth = [-1] * (N + 1)
node_order = [0] * (N + 1)
order = 1
st = [(R, 0)]
while st:
    node, depth = st.pop()
    if node_depth[node] > -1:
        continue
    node_depth[node] = depth
    node_order[node] = order
    order += 1
    for next in adj[node]:
        if node_depth[next] == -1:
            st.append((next, depth + 1))

print(sum(node_depth[i] * node_order[i] for i in range(1, N + 1)))
