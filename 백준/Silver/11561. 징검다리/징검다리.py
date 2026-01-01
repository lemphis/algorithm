import sys

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N = int(input())
    lo = 1
    hi = N
    while lo + 1 < hi:
        mid = (lo + hi) >> 1
        if (mid * (mid + 1)) >> 1 <= N:
            lo = mid
        else:
            hi = mid

    print(lo)
