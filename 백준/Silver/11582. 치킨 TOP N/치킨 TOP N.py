N = int(input())
nums = list(map(int, input().split()))
k = int(input())
gap = N // k
result = []
for i in range(0, N, gap):
    result.extend(sorted(nums[i : i + gap]))

print(*result)
