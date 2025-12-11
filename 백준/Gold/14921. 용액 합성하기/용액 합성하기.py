import sys

input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

A.sort()

ans = float("inf")
l = 0
r = N - 1
while l < r:
    total = A[l] + A[r]
    if abs(ans) > abs(total):
        ans = total

    if total > 0:
        r -= 1
    elif total < 0:
        l += 1
    else:
        break

print(ans)
