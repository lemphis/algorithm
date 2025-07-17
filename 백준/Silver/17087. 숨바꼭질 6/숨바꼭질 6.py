import math

N, S = map(int, input().split())
A = [abs(S - a) for a in list(map(int, input().split()))]

print(math.gcd(*A))
