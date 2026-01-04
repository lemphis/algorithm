import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(M)]

if N == M == 1:
    print("Yes")
    exit()

visited = [[False] * N for _ in range(M)]
dq = deque([(0, 0)])
visited[0][0] = True
while dq:
    r, c = dq.pop()
    if r == M - 1 and c == N - 1:
        print("Yes")
        exit()
    for dr, dc in [(0, 1), (1, 0)]:
        nr, nc = r + dr, c + dc
        if 0 <= nr < M and 0 <= nc < N and board[nr][nc] == 1 and not visited[nr][nc]:
            dq.append((nr, nc))
            visited[nr][nc] = True

print("No")
