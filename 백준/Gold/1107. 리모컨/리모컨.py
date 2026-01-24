import sys

input = sys.stdin.readline

N = int(input())
M = int(input())
broken_buttons = set(map(int, input().split()))

ans = abs(N - 100)
for channel in range(1_000_000):
    s = str(channel)

    possible = True
    for c in s:
        if int(c) in broken_buttons:
            possible = False
            break

    if not possible:
        continue

    presses = len(s) + abs(N - channel)
    ans = min(ans, presses)

print(ans)
