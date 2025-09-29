import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())
S, E = map(int, input().split())

teleports = {}
for _ in range(M):
    x, y = map(int, input().split())
    if x in teleports:
        teleports[x].append(y)
    else:
        teleports[x] = [y]
    if y in teleports:
        teleports[y].append(x)
    else:
        teleports[y] = [x]

visited = [False] * (N + 1)
visited[S] = True
dq = deque([(S, 0)])
while dq:
    now, time = dq.popleft()
    if now == E:
        print(time)
        break
    if now + 1 <= N and not visited[now + 1]:
        dq.append((now + 1, time + 1))
        visited[now + 1] = True
    if now - 1 > 0 and not visited[now - 1]:
        dq.append((now - 1, time + 1))
        visited[now - 1] = True
    if now in teleports:
        for next in teleports[now]:
            if not visited[next]:
                dq.append((next, time + 1))
                visited[next] = True
