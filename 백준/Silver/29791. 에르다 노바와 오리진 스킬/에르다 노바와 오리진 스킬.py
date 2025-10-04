import sys

input = sys.stdin.readline

N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

A.sort()
B.sort()

a_count = b_count = 1
a_time = A[0]
b_time = B[0]
for a in A[1:]:
    if a >= a_time + 100:
        a_count += 1
        a_time = a
for b in B[1:]:
    if b >= b_time + 360:
        b_count += 1
        b_time = b

print(a_count, b_count)
