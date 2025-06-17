def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)


N = int(input())
for _ in range(N):
    nums = sorted(list(map(int, input().split())), reverse=True)
    max_gcd = 0
    for i in range(len(nums) - 1):
        for j in range(i + 1, len(nums)):
            max_gcd = max(max_gcd, gcd(nums[i], nums[j]))
    print(max_gcd)
