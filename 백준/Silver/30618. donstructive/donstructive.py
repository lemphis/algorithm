N = int(input())

nums = [0] * N
for i in range(N // 2):
    nums[i] = i * 2 + 1
    nums[N - i - 1] = (i + 1) * 2
if N & 1:
    nums[N // 2] = N
print(*nums, sep=" ")
