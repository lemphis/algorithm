import sys

input = sys.stdin.readline

N = int(input())
t = list(map(int, input().split()))

t.sort()

muscle_loss = 0
size = N - 1 if N & 1 else N
for i in range(size // 2):
    muscle_loss = max(muscle_loss, t[i] + t[size - 1 - i])

if N & 1:
    muscle_loss = max(muscle_loss, t[N - 1])

print(muscle_loss)
