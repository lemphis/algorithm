import sys

input = sys.stdin.readline

N = int(input())
H = list(map(int, input().split()))

arrows = [0] * 1_000_001
ans = 0
for h in H:
    if arrows[h] > 0:
        arrows[h] -= 1
    else:
        ans += 1
    arrows[h - 1] += 1

print(ans)
