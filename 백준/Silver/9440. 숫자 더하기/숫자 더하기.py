while len(nums := list(input().split())[1:]) > 1:
    nums.sort(key=int)
    left = []
    right = []
    for i in range(len(nums)):
        if nums[i] != "0":
            left.append(nums[i])
            right.append(nums[i + 1])
            nums.pop(i)
            nums.pop(i)
            break
    for i in range(0, len(nums), 2):
        left.append(nums[i])
        if i < len(nums) - 1:
            right.append(nums[i + 1])

    print(int("".join(left)) + int("".join(right)))
