import sys
from collections import deque
from itertools import combinations

input = sys.stdin.readline

A, B, C = map(int, input().split())

total = A + B + C
if total % 3 != 0:
    print(0)
    exit()

dq = deque([(min(A, B, C), max(A, B, C))])
visited = [[False] * (total + 1) for _ in range(total + 1)]
while dq:
    X, Y = dq.popleft()
    if X == Y and X == total - (X + Y):
        print(1)
        exit()

    Z = total - (X + Y)
    nums = sorted([X, Y, Z])

    for a, b in combinations(nums, 2):
        min_num, max_num = min(a + a, b - a), max(a + a, b - a)
        if not visited[min_num][max_num]:
            visited[min_num][max_num] = True
            dq.append((min_num, max_num))

print(0)
