max_num = max_r = max_c = -1

for r in range(9):
    nums = list(map(int, input().split()))
    for c in range(9):
        if nums[c] > max_num:
            max_num = nums[c]
            max_r, max_c = r + 1, c + 1

print(max_num)
print(max_r, max_c)