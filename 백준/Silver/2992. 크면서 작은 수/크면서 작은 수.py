import sys
import itertools

input = sys.stdin.readline

X = tuple(map(int, input().strip()))

temp = list(X)
temp.sort()
nums = sorted(set(itertools.permutations(temp)))
idx = nums.index(X)

print(0 if idx == len(nums) - 1 else "".join(list(map(str, nums[idx + 1]))))
