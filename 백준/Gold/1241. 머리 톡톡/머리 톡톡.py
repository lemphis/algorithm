import sys

input = sys.stdin.readline

N = int(input())
nums = [int(input()) for _ in range(N)]

max_num = max(nums)
counts = [0] * (max_num + 1)
for num in nums:
    counts[num] += 1

ans = [0] * (max_num + 1)
for i in range(1, max_num + 1):
    if counts[i] == 0:
        continue

    multiple = i
    while multiple <= max_num:
        ans[multiple] += counts[i]
        multiple += i

print(*[ans[nums[i]] - 1 for i in range(N)], sep="\n")
