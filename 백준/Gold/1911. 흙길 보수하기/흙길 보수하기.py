import sys

input = sys.stdin.readline

N, L = map(int, input().split())
puddles = [tuple(map(int, input().split())) for _ in range(N)]

puddles.sort()

pos = 0
ans = 0
for s, e in puddles:
    if s > pos:
        pos = s

    l = e - pos
    count = l // L
    if l % L > 0:
        count += 1

    ans += count
    pos += count * L

print(ans)
