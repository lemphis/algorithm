import sys

input = sys.stdin.readline

N, L, R, X = map(int, input().split())
A = list(map(int, input().split()))

ans = 0
for mask in range(1 << N):
    problems = []
    for i in range(N):
        if mask & (1 << i):
            problems.append(A[i])

    if len(problems) < 2:
        continue

    min_level = min(problems)
    max_level = max(problems)
    total_level = sum(problems)

    if L <= total_level <= R and max_level - min_level >= X:
        ans += 1

print(ans)
