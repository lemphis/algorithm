import sys

input = sys.stdin.readline

N, K = map(int, input().split())
X = list(map(int, input().split()))

last_clap = 0
count = 0
for quack in X:
    if quack > last_clap:
        last_clap = quack + K
        count += 1

print(count)
