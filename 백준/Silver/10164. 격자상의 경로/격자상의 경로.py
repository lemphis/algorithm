import sys
import math

input = sys.stdin.readline

N, M, K = map(int, input().split())

if K == 0:
    print(math.comb((N - 1) + (M - 1), N - 1))
else:
    r, c = (K - 1) // M, (K - 1) % M
    print(math.comb(r + c, r) * math.comb((N - 1 - r) + (M - 1 - c), N - 1 - r))
