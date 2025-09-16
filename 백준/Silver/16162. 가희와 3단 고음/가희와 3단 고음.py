import sys

input = sys.stdin.readline

N, A, D = map(int, input().split())
scales = list(map(int, input().split()))

level = 0
for scale in scales:
    if scale == A:
        level += 1
        A += D

print(level)
