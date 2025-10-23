import sys
from collections import deque

input = sys.stdin.readline

N, K = map(int, input().split())

dq = deque([i for i in range(N)])
while len(dq) >= K:
    first = dq.popleft()
    for _ in range(K - 1):
        dq.popleft()
    dq.append(first)

print(dq[0] + 1)
