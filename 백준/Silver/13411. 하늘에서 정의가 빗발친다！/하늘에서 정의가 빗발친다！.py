import sys

input = sys.stdin.readline

N = int(input())
poses = [tuple(map(int, input().split())) for i in range(N)]

dist = [(((x**2 + y**2) ** 0.5) / v, i + 1) for i, (x, y, v) in enumerate(poses)]

dist.sort()

print(*[i for _, i in dist], sep="\n")
