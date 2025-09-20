import sys

input = sys.stdin.readline

N, K = map(int, input().split())
A = list(map(int, input().split()))

prefix = [0] * (N + 1)
for i in range(1, N + 1):
    prefix[i] = prefix[i - 1] + A[i - 1]

ans = sum(sorted(prefix[1:], reverse=True)[:K])

print(ans)
