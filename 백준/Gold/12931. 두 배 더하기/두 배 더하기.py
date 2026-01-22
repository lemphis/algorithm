import sys

input = sys.stdin.readline

N = int(input())
B = list(map(int, input().split()))

count = 0
while True:
    total = 0
    for i in range(N):
        if B[i] % 2 == 1:
            B[i] -= 1
            count += 1
        total += B[i]

    if total == 0:
        break

    for i in range(N):
        B[i] //= 2

    count += 1

print(count)
