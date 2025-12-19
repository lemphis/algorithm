import sys
from collections import deque

input = sys.stdin.readline
dir = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]


def erase(r, c):
    dq = deque([(r, c, farm[r][c])])
    visited[r][c] = True
    while dq:
        now_r, now_c, now_h = dq.popleft()
        for dr, dc in dir:
            nr, nc = now_r + dr, now_c + dc
            if (
                0 <= nr < N
                and 0 <= nc < M
                and farm[nr][nc] <= now_h
                and not visited[nr][nc]
            ):
                dq.append((nr, nc, farm[nr][nc]))
                visited[nr][nc] = True


N, M = map(int, input().split())
farm = [list(map(int, input().split())) for _ in range(N)]

poses_order = [(farm[r][c], r, c) for r in range(N) for c in range(M) if farm[r][c] > 0]
poses_order.sort(reverse=True)

visited = [[False] * M for _ in range(N)]
ans = 0
for _, r, c in poses_order:
    if not visited[r][c]:
        erase(r, c)
        ans += 1

print(ans)
