import sys
import bisect

input = sys.stdin.readline

N, H = map(int, input().split())

stalagmites = [0] * (N // 2)
stalactites = [0] * (N // 2)
for i in range(N):
    length = int(input())
    if i & 1:
        stalactites[i // 2] = length
    else:
        stalagmites[i // 2] = length

stalagmites.sort()
stalactites.sort()

counts = [0] * H
for h in range(1, H + 1):
    stalagmites_count = len(stalagmites) - bisect.bisect_left(stalagmites, h)
    stalactites_count = len(stalactites) - bisect.bisect_left(stalactites, H - h + 1)
    counts[h - 1] = stalagmites_count + stalactites_count

counts.sort()

print(counts[0], counts.count(counts[0]))
