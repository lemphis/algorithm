import sys

input = sys.stdin.readline

n = int(input())
nums = list(map(int, input().split()))

diffs = [abs(nums[0] - num) for num in nums[1:]]
for i in range(1_000_000, 1, -1):
    if all(d % i == 0 for d in diffs):
        print(i)
        break
else:
    print(1)
