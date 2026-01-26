import sys
from collections import deque

input = sys.stdin.readline

N, k = map(int, input().split())
left = list(input().strip())
right = list(input().strip())

pos = (True, 0, -1)
dq = deque([pos])
left_visited = [False] * N
right_visited = [False] * N
left_visited[0] = True
while dq:
    is_left, idx, time = dq.popleft()
    if idx >= N - k:
        print(1)
        exit()

    if idx < N - 1 and (
        (is_left and left[idx + 1] == "1" and not left_visited[idx + 1])
        and idx + 1 > time + 1
    ):
        dq.append((is_left, idx + 1, time + 1))
        left_visited[idx + 1] = True
    if idx < N - 1 and (
        (not is_left and right[idx + 1] == "1" and not right_visited[idx + 1])
        and idx + 1 > time + 1
    ):
        dq.append((is_left, idx + 1, time + 1))
        right_visited[idx + 1] = True
    if (
        idx > 0
        and ((is_left and left[idx - 1] == "1" and not left_visited[idx - 1]))
        and idx - 1 > time + 1
    ):
        dq.append((is_left, idx - 1, time + 1))
        left_visited[idx - 1] = True
    if (
        idx > 0
        and ((not is_left and right[idx - 1] == "1" and not right_visited[idx - 1]))
        and idx - 1 > time + 1
    ):
        dq.append((is_left, idx - 1, time + 1))
        right_visited[idx - 1] = True
    if idx < N - k and (
        is_left and right[idx + k] == "1" and not right_visited[idx + k]
    ):
        dq.append((False, idx + k, time + 1))
        right_visited[idx + k] = True
    if idx < N - k and (
        not is_left and left[idx + k] == "1" and not left_visited[idx + k]
    ):
        dq.append((True, idx + k, time + 1))
        left_visited[idx + k] = True

print(0)
