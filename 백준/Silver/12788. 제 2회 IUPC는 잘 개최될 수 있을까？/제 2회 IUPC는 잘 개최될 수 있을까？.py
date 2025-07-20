import sys

input = sys.stdin.readline

N = int(input())
M, K = map(int, input().split())
A = list(map(int, input().split()))

A.sort(reverse=True)
total_pen_count = M * K

idx = 0
while total_pen_count > 0 and idx < N:
    total_pen_count -= A[idx]
    idx += 1

print("STRESS" if total_pen_count > 0 else idx)
