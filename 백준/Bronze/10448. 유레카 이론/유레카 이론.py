nums = [i * (i + 1) // 2 for i in range(1, 46)]
ans = [False] * 1_001
for i in nums:
    for j in nums:
        for k in nums:
            if i + j + k <= 1000:
                ans[i + j + k] = True

T = int(input())
for _ in range(T):
    K = int(input())
    print(1 if ans[K] else 0)
