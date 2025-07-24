import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
nums = list(map(int, input().split()))
a, b = map(int, input().split())

dq = deque([(a - 1, 0)])
visited = [False] * N
visited[a - 1] = True
while dq:
    now_pos, now_count = dq.popleft()
    if now_pos == b - 1:
        print(now_count)
        exit()

    times = 1
    while (next_pos := now_pos + (-times * nums[now_pos])) >= 0:
        if not visited[next_pos]:
            dq.append((next_pos, now_count + 1))
            visited[next_pos] = True
        times += 1
    times = 1
    while (next_pos := now_pos + (times * nums[now_pos])) < N:
        if not visited[next_pos]:
            dq.append((next_pos, now_count + 1))
            visited[next_pos] = True
        times += 1

print(-1)
