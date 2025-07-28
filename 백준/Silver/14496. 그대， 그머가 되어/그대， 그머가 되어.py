import sys
from collections import deque

input = sys.stdin.readline

a, b = map(int, input().split())
N, M = map(int, input().split())
m = [[False] * N for _ in range(N)]
for _ in range(M):
    s, t = map(int, input().split())
    m[s - 1][t - 1] = True
    m[t - 1][s - 1] = True

dq = deque([(a - 1, 0)])
visited = [False] * N
visited[a - 1] = True
count = 0
while dq:
    now, now_count = dq.popleft()
    if now == b - 1:
        print(now_count)
        exit()
    for i in range(N):
        if m[now][i] and not visited[i]:
            dq.append((i, now_count + 1))
            visited[i] = True

print(-1)
