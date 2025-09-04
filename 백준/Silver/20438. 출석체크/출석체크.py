import sys

input = sys.stdin.readline

N, K, Q, M = map(int, input().split())
sleppy_students = list(map(int, input().split()))
start_students = list(map(int, input().split()))
queries = [tuple(map(int, input().split())) for _ in range(M)]

sleep = [False] * (N + 3)
check = [False] * (N + 3)
for student in sleppy_students:
    sleep[student] = True
for student in start_students:
    if sleep[student]:
        continue
    for i in range(student, N + 3, student):
        if not sleep[i]:
            check[i] = True

prefix_sum = [0] * (N + 3)
for i in range(3, N + 3):
    prefix_sum[i] += prefix_sum[i - 1] + (0 if check[i] else 1)

ans = []
for S, E in queries:
    ans.append(prefix_sum[E] - prefix_sum[S - 1])

print(*ans, sep="\n")
