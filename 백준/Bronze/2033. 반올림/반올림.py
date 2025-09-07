import sys

N = int(sys.stdin.readline().strip())

d = 10
while N >= d:
    N = (N + d // 2) // d * d
    d *= 10

print(N)