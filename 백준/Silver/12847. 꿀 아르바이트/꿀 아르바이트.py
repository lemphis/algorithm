import sys

input = sys.stdin.readline

n, m = map(int, input().split())
T = list(map(int, input().split()))

total = sum(T[:m])
ans = total
for i in range(m, n):
    total = total - T[i - m] + T[i]
    ans = max(ans, total)

print(ans)
