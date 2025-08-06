def dfs(n, depth, nums):
    global count
    if n == depth:
        if sum(nums) % 3 == 0:
            count += 1
        return

    for i in range(3):
        nums.append(i)
        dfs(n, depth + 1, nums)
        nums.pop()


N = int(input())

count = 0

dfs(N, 1, [1])
dfs(N, 1, [2])

print(count)
