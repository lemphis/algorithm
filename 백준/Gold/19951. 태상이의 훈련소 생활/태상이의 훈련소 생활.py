import sys

input = sys.stdin.readline

N,M = map(int, input().split())
H = list(map(int, input().split()))
instructions = [list(map(int, input().split())) for _ in range(M)]

diff = [0] *(N+1)
for a,b,k in instructions:
    diff[a-1] += k
    diff[b] -= k

total_diff = 0
for i in range(N):
    total_diff += diff[i]
    H[i] += total_diff

print(" ".join(map(str, H)))
