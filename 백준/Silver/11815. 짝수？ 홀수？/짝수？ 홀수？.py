import math

N = int(input())
nums = list(map(int, input().split()))

print(*[1 if math.isqrt(n) ** 2 == n else 0 for n in nums])
