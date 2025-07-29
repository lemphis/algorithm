import sys
from collections import deque

input = sys.stdin.readline

N, K = map(int, input().split())
examiner = [list(map(int, input().split())) for _ in range(N)]
S, X, Y = map(int, input().split())

order = []
for r in range(N):
    for c in range(N):
        if examiner[r][c] > 0:
            order.append((examiner[r][c], r, c))

order.sort()

dq = deque(order)
dir = [(1, 0), (0, -1), (-1, 0), (0, 1)]
for _ in range(S):
    for _ in range(len(dq)):
        virus, r, c = dq.popleft()
        for dr, dc in dir:
            nr, nc = r + dr, c + dc
            if 0 <= nr < N and 0 <= nc < N and examiner[nr][nc] == 0:
                examiner[nr][nc] = virus
                dq.append((virus, nr, nc))

print(examiner[X - 1][Y - 1])
