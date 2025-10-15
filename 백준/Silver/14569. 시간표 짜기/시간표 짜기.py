import sys

input = sys.stdin.readline

N = int(input())
classes = [set(list(map(int, input().split()))[1:]) for _ in range(N)]
M = int(input())
students = [set(list(map(int, input().split()))[1:]) for _ in range(M)]

ans = []
for s in students:
    count = 0
    for c in classes:
        if c <= s:
            count += 1
    ans.append(count)

print(*ans, sep="\n")
