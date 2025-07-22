import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())

trains = [deque([False] * 20) for _ in range(N)]
for _ in range(M):
    commands = tuple(map(int, input().split()))
    if commands[0] == 1:
        trains[commands[1] - 1][commands[2] - 1] = True
    elif commands[0] == 2:
        trains[commands[1] - 1][commands[2] - 1] = False
    elif commands[0] == 3:
        trains[commands[1] - 1].pop()
        trains[commands[1] - 1].appendleft(False)
    else:
        trains[commands[1] - 1].popleft()
        trains[commands[1] - 1].append(False)

s = {sum(1 << i if train[i] else 0 for i in range(20)) for train in trains}

print(len(s))
