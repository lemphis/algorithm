import sys
from collections import deque

input = sys.stdin.readline

N, M, K = map(int, input().split())

mid = (0, 0) if K == 0 else ((K - 1) // M, (K - 1) % M)

dq = deque([(0, 0)])
mid_count = 0
while dq:
    r, c = dq.popleft()
    if (r, c) == mid:
        mid_count += 1
        continue
    for dr, dc in [(0, 1), (1, 0)]:
        nr, nc = r + dr, c + dc
        if 0 <= nr < mid[0] + 1 and 0 <= nc < mid[1] + 1:
            dq.append((nr, nc))

end_count = 0
dq = deque([mid])
while dq:
    r, c = dq.popleft()
    if (r, c) == (N - 1, M - 1):
        end_count += 1
        continue
    for dr, dc in [(0, 1), (1, 0)]:
        nr, nc = r + dr, c + dc
        if 0 <= nr < N and 0 <= nc < M:
            dq.append((nr, nc))

print(end_count if K == 0 else mid_count * end_count)
