import sys

input = sys.stdin.readline

D, N = map(int, input().split())
oven_diameter = list(map(int, input().split()))
pizza_diameter = list(map(int, input().split()))

for i in range(1, D):
    oven_diameter[i] = min(oven_diameter[i], oven_diameter[i - 1])

floor = D - 1
for pizza in pizza_diameter:
    while floor >= 0 and oven_diameter[floor] < pizza:
        floor -= 1

    if floor < 0:
        print(0)
        exit()

    floor -= 1

print(floor + 2)
