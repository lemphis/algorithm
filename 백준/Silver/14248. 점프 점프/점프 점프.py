import sys
from collections import deque

input = sys.stdin.readline

n = int(input())
A = list(map(int, input().split()))
s = int(input())

visited = [False] * n
visited[s - 1] = True
dq = deque([s - 1])
while dq:
    pos = dq.popleft()
    for d in (-A[pos], A[pos]):
        next = pos + d
        if 0 <= next < n and not visited[next]:
            visited[next] = True
            dq.append(next)

print(sum(visited))
