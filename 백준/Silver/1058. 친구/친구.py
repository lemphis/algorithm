N = int(input())
graph = [list(input()) for _ in range(N)]
max_count = 0
for node in range(N):
    dist = [50] * N
    for i in range(N):
        if graph[node][i] == "Y":
            dist[i] = 1
    for i in range(N):
        if dist[i] == 1:
            for j in range(N):
                if j != node and graph[i][j] == "Y":
                    dist[j] = min(dist[j], dist[i] + 1)
    max_count = max(max_count, sum(1 for count in dist if count < 50))

print(max_count)
