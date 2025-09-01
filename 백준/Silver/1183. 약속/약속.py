import sys

input = sys.stdin.readline

N = int(input())
diffs = list(
    map(lambda x: x[1] - x[0], [list(map(int, input().split())) for _ in range(N)])
)

if N & 1:
    print(1)
    exit()

diffs.sort()

print(diffs[N // 2] - diffs[N // 2 - 1] + 1)
