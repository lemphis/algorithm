import sys

input = sys.stdin.readline

n = int(input())
d = {}
for _ in range(n):
    s = input().strip()
    d[s] = d.get(s, 0) + 1

print(*max(d.items(), key=lambda x: (x[1], x[0])))
