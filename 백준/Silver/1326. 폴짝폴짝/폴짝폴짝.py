import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
nums = list(map(int, input().split()))
a, b = map(int, input().split())
a -= 1
b -= 1

dq = deque([(a, 0)])
visited = [False] * N
visited[a] = True
while dq:
    pos, count = dq.popleft()
    if pos == b:
        print(count)
        break

    step = nums[pos]
    for next_pos in range(pos + step, N, step):
        if not visited[next_pos]:
            dq.append((next_pos, count + 1))
            visited[next_pos] = True
    for next_pos in range(pos - step, -1, -step):
        if not visited[next_pos]:
            dq.append((next_pos, count + 1))
            visited[next_pos] = True
else:
    print(-1)
