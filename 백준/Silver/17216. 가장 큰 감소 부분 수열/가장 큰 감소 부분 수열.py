N = int(input())
nums = list(map(int, input().split()))

dp = [num for num in nums]
for i in range(1, N):
    for j in range(i):
        if nums[i] < nums[j]:
            dp[i] = max(dp[i], dp[j] + nums[i])

print(max(dp))
