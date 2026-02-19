import sys
from math import gcd

input = sys.stdin.readline

n = int(input())
nums = list(map(int, input().split()))

diffs = [abs(nums[0] - num) for num in nums[1:]]
ans = diffs[0]
for d in diffs[1:]:
    ans = gcd(ans, d)

print(ans)
