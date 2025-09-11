import sys

input = sys.stdin.readline

N = int(input())
target = list(map(int, input().split()))
light = [0] * N

count = 0
for i in range(N):
    if target[i] != light[i]:
        for j in range(i, min(i + 3, N)):
            light[j] ^= 1
        count += 1

print(count)
