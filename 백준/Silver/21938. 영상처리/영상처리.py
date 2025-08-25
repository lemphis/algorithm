import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())
pixels = [
    [
        sum(row[i * 3 : i * 3 + 3]) // 3
        for row in [list(map(int, input().split()))]
        for i in range(M)
    ]
    for _ in range(N)
]
T = int(input())

for r in range(N):
    for c in range(M):
        pixels[r][c] = pixels[r][c] >= T

dq = deque()
count = 0
dir = [(1, 0), (0, -1), (-1, 0), (0, 1)]
for r in range(N):
    for c in range(M):
        if pixels[r][c]:
            pixels[r][c] = False
            dq.append((r, c))
            while dq:
                now_r, now_c = dq.popleft()
                for dr, dc in dir:
                    next_r, next_c = now_r + dr, now_c + dc
                    if 0 <= next_r < N and 0 <= next_c < M and pixels[next_r][next_c]:
                        dq.append((next_r, next_c))
                        pixels[next_r][next_c] = False
            count += 1

print(count)
