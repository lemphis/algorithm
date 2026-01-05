import sys

input = sys.stdin.readline

N = int(input())
works = [tuple(map(int, input().split())) for _ in range(N)]

works.sort(key=lambda x: x[1], reverse=True)

begin_time = works[0][1]
for t, s in works:
    begin_time = min(begin_time, s) - t

print(begin_time if begin_time >= 0 else -1)
