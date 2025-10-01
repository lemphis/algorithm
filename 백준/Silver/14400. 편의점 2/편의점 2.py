import sys

input = sys.stdin.readline

n = int(input())
positions = [tuple(map(int, input().split())) for _ in range(n)]

sorted_x = sorted([x for x, _ in positions])
sorted_y = sorted([y for _, y in positions])

center_x = sorted_x[n // 2]
center_y = sorted_y[n // 2]

x_diff_total = sum([abs(center_x - x) for x in sorted_x])
y_diff_total = sum([abs(center_y - y) for y in sorted_y])

print(x_diff_total + y_diff_total)
