import sys

input = sys.stdin.readline

N, M = map(int, input().split())
keys = [input().split() for _ in range(M)]

keys.sort(key=lambda x: (int(x[1]), int(x[0])))

print("".join([key[2] for key in keys]))
