import sys

input = sys.stdin.readline

N = int(input())
B = list(map(int, input().split()))

for i in range(N):
    num = B[i]
    two = 0
    while num % 2 == 0:
        two += 1
        num //= 2

    num = B[i]
    three = 0
    while num % 3 == 0:
        three += 1
        num //= 3

    B[i] = (B[i], two, three)

B.sort(key=lambda x: (-x[2], x[1]))

print(" ".join(str(x[0]) for x in B))
