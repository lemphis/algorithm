import sys

input = sys.stdin.readline

n = int(input())
d = {}
m = ("", 0)
for _ in range(n):
    s = input().strip()
    if s in d:
        d[s] += 1
    else:
        d[s] = 1

    if d[s] > m[1] or (d[s] == m[1] and s > m[0]):
        m = (s, d[s])

print(*m)
