import sys

input = sys.stdin.readline

N, M = map(int, input().split())
A = list(map(int, input().split()))

lo = 0
hi = 1_000_000 * 1_000_000 + 1
while lo + 1 < hi:
    mid = (lo + hi) >> 1
    if sum(mid // a for a in A) >= M:
        hi = mid
    else:
        lo = mid

print(hi)
