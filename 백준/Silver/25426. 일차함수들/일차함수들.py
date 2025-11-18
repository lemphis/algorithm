import sys

input = sys.stdin.readline

N = int(input())
nums = [tuple(map(int, input().split())) for _ in range(N)]

nums.sort(reverse=True)

print(sum([nums[i][0] * (N - i) + nums[i][1] for i in range(N)]))
