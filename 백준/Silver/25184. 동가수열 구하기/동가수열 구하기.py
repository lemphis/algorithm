N = int(input())

nums = []
if N & 1:
    nums.append(N)
for i in range(N // 2):
    nums.append(i + 1 + (N // 2))
    nums.append(i + 1)


print(*nums, sep=" ")
