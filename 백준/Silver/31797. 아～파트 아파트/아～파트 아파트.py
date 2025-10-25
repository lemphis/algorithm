import sys

input = sys.stdin.readline

N, M = map(int, input().split())
heights = [tuple(map(int, input().split())) for _ in range(M)]
hands = []
for i in range(M):
    hands.append((heights[i][0], i + 1))
    hands.append((heights[i][1], i + 1))

hands.sort()

print([p for _, p in hands][(N - 1) % (M * 2)])
