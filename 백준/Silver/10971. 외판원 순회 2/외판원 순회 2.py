N = int(input())
map = [list(map(int, input().split())) for _ in range(N)]

min_cost = 1e9
visited = [False] * N


def dfs(start_node, node, depth, cost):
    global min_cost

    if depth == N - 1:
        if map[node][start_node] > 0:
            min_cost = min(min_cost, cost + map[node][start_node])
        return

    for i in range(N):
        if map[node][i] > 0 and not visited[i] and cost < min_cost:
            visited[i] = True
            dfs(start_node, i, depth + 1, cost + map[node][i])
            visited[i] = False


for i in range(N):
    visited[i] = True
    dfs(i, i, 0, 0)
    visited[i] = False

print(min_cost)
