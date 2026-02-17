import sys
from collections import deque

input = sys.stdin.readline

M, N = map(int, input().split())
maze = [list(map(int, list(input().strip()))) for _ in range(N)]

dq = deque([(0, 0)])
dist = [[1e9] * M for _ in range(N)]
dist[0][0] = 0
dir = [(1, 0), (0, -1), (-1, 0), (0, 1)]
while dq:
    r, c = dq.popleft()
    for dr, dc in dir:
        nr, nc = r + dr, c + dc
        if 0 <= nr < N and 0 <= nc < M and dist[nr][nc] > dist[r][c] + maze[nr][nc]:
            if maze[nr][nc]:
                dq.append((nr, nc))
            else:
                dq.appendleft((nr, nc))

            dist[nr][nc] = dist[r][c] + maze[nr][nc]

print(dist[N - 1][M - 1])
