import sys

input = sys.stdin.readline

N = int(input())
cranes = list(map(int, input().split()))
M = int(input())
boxes = list(map(int, input().split()))

cranes.sort(reverse=True)
boxes.sort(reverse=True)

if boxes[0] > cranes[0]:
    print(-1)
else:
    minutes = 0
    visited = [False] * M
    pos = [0] * N
    moved = 0
    while moved < M:
        for i in range(N):
            while pos[i] < M:
                if not visited[pos[i]] and cranes[i] >= boxes[pos[i]]:
                    visited[pos[i]] = True
                    pos[i] += 1
                    moved += 1
                    break
                pos[i] += 1
        minutes += 1
    print(minutes)
