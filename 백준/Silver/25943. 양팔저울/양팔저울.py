import sys

input = sys.stdin.readline

n = int(input())
gravels = list(map(int, input().split()))

left = gravels[0]
right = gravels[1]
for gravel in gravels[2:]:
    if left <= right:
        left += gravel
    else:
        right += gravel

diff = abs(left - right)
weights = [100, 50, 20, 10, 5, 2, 1]
total_count = 0
for weight in weights:
    count = diff // weight
    total_count += count
    diff -= weight * count

print(total_count)
