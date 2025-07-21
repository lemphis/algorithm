import sys
from collections import deque

input = sys.stdin.readline

M, N = map(int, input().split())
grid = [list(input().strip()) for _ in range(M)]

visited = [[False] * N for _ in range(M)]
dir = [(1, 0), (0, -1), (-1, 0), (0, 1)]
reachable = False
for col in range(N):
    if grid[0][col] == "0":
        dq = deque([(0, col)])
        while dq:
            r, c = dq.popleft()
            for dr, dc in dir:
                nr, nc = r + dr, c + dc
                if (
                    0 <= nr < M
                    and 0 <= nc < N
                    and not visited[nr][nc]
                    and grid[nr][nc] == "0"
                ):
                    dq.append((nr, nc))
                    visited[nr][nc] = True

print("YES" if any(v for v in visited[M - 1]) else "NO")
