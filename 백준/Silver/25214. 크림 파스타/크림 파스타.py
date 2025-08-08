N = int(input().strip())
nums = list(map(int, input().split()))

min_num = nums[0]
max_diff = 0
ans = [0]
for num in nums[1:]:
    if num - min_num > max_diff:
        max_diff = num - min_num
    if min_num > num:
        min_num = num
    ans.append(max_diff)

print(" ".join(map(str, ans)))
