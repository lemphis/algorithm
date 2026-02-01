import sys
from collections import deque

input = sys.stdin.readline

row, col = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(row)]
dir = [(1, 0), (0, -1), (-1, 0), (0, 1)]

time = 0
last_cheeze_count = 0
while True:
    cheeze_count = sum(board[r][c] for r in range(row) for c in range(col))
    if cheeze_count == 0:
        break
    last_cheeze_count = cheeze_count

    air_areas = []
    dq = deque([(0, 0)])
    visited = [[False] * col for _ in range(row)]
    visited[0][0] = True
    while dq:
        r, c = dq.popleft()
        for dr, dc in dir:
            nr, nc = r + dr, c + dc
            if (
                0 <= nr < row
                and 0 <= nc < col
                and not visited[nr][nc]
                and not board[nr][nc]
            ):
                dq.append((nr, nc))
                air_areas.append((nr, nc))
                visited[nr][nc] = True
    for r, c in air_areas:
        for dr, dc in dir:
            nr, nc = r + dr, c + dc
            if 0 <= nr < row and 0 <= nc < col and board[nr][nc]:
                board[nr][nc] = 0

    time += 1

print(time)
print(last_cheeze_count)
