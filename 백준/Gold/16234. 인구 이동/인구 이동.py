import sys
from collections import deque

input = sys.stdin.readline

N, L, R = map(int, input().split())
countries = [list(map(int, input().split())) for _ in range(N)]

count = 0
dir = [(1, 0), (0, -1), (-1, 0), (0, 1)]
while True:
    visited = [[False] * N for _ in range(N)]
    need_change_arr = []
    for r in range(N):
        for c in range(N):
            if not visited[r][c]:
                visited[r][c] = True
                dq = deque([(r, c)])
                arr = [(r, c)]
                while dq:
                    row, col = dq.popleft()
                    for dr, dc in dir:
                        nr, nc = row + dr, col + dc
                        if (
                            0 <= nr < N
                            and 0 <= nc < N
                            and not visited[nr][nc]
                            and L <= abs(countries[row][col] - countries[nr][nc]) <= R
                        ):
                            dq.append((nr, nc))
                            arr.append((nr, nc))
                            visited[nr][nc] = True
                if len(arr) > 1:
                    need_change_arr.extend([arr])

    if len(need_change_arr) > 0:
        for arr in need_change_arr:
            new_population = sum(countries[row][col] for row, col in arr) // len(arr)
            for row, col in arr:
                countries[row][col] = new_population
    else:
        break

    count += 1

print(count)
