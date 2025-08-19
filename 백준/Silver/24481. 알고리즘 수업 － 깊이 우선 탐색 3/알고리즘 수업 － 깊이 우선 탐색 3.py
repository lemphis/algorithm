def dfs_iterative(adj, node_depth, start):
    st = [(start, 0)]
    while st:
        node, depth = st.pop()
        if node_depth[node] < 0:
            node_depth[node] = depth
        for next in reversed(adj[node]):
            if node_depth[next] < 0:
                st.append((next, depth + 1))


N, M, R = map(int, input().split())
adj = [list() for _ in range(N)]
for _ in range(M):
    u, v = map(int, input().split())
    adj[v - 1].append(u - 1)
    adj[u - 1].append(v - 1)

for r in adj:
    r.sort()

node_depth = [-1] * N
node_depth[R - 1] = 0

dfs_iterative(adj, node_depth, R - 1)

print(*node_depth, sep="\n")
