import sys
import math

input = sys.stdin.readline

N, M = map(int, input().split())

g = math.gcd(N, M)

print(M - g)
