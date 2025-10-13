import sys

input = sys.stdin.readline

N, K = map(int, input().split())
experiences = list(map(int, input().split()))

experiences.sort()

ans = 0
for i in range(N):
    ans += experiences[i] * min(i, K)

print(ans)
