import sys

input = sys.stdin.readline
N = int(input())
nums = [0] + [int(input()) for i in range(N)]

visited = [False] * (N + 1)
ans = []


def dfs(start, idx, arr, nums, depth):
    global N, visited, ans
    if depth == N:
        return
    if nums[idx] == start:
        for num in arr:
            visited[num] = True
        ans.extend(arr)
        return

    arr.append(nums[idx])
    dfs(start, nums[idx], arr, nums, depth + 1)


for i in range(1, N + 1):
    if not visited[i]:
        dfs(i, i, [i], nums, 1)

print(len(ans))
print(*sorted(ans), sep="\n")
