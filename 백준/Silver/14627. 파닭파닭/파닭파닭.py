S, C = map(int, input().split())
lens = [int(input()) for _ in range(S)]

lo = 0
hi = max(lens) + 1
while lo + 1 < hi:
    mid = (lo + hi) >> 1
    if sum(l // mid for l in lens) >= C:
        lo = mid
    else:
        hi = mid

print(sum(lens) - (lo * C))
