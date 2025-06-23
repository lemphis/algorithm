from itertools import combinations

N, K = map(int, input().split())
poses = [tuple(map(int, input().split())) for _ in range(N)]


def manhattan(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])


ans = float("inf")

for shelters in combinations(poses, K):
    worst = 0
    for house in poses:
        dist_to_nearest = min(manhattan(house, s) for s in shelters)
        worst = max(worst, dist_to_nearest)
    ans = min(ans, worst)

print(ans)
