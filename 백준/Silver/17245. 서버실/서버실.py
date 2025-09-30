import sys

input = sys.stdin.readline

N = int(input())
racks = [list(map(int, input().split())) for _ in range(N)]

half = (sum(sum(row) for row in racks) + 1) // 2
lo = 0
hi = max(max(row) for row in racks)
while lo + 1 < hi:
    mid = (lo + hi) // 2
    total = 0
    for row in racks:
        for num in row:
            total += min(num, mid)
    if total >= half:
        hi = mid
    else:
        lo = mid

print(hi)
