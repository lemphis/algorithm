import sys

input = sys.stdin.readline

M = int(input())
m = {}
for _ in range(M):
    line = list(map(int, input().split()))
    if line[0] == 1:
        m[line[2]] = line[1]
    else:
        print(m[line[1]])
