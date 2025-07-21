import sys

input = sys.stdin.readline

n = int(input())
s = input().strip()

maze = [[False] * 101 for _ in range(101)]
dir = 0
max_r = max_c = min_r = min_c = now_r = now_c = 50
maze[now_r][now_c] = True
for c in s:
    if c == "L":
        dir = (dir + 4 - 1) % 4
    elif c == "R":
        dir = (dir + 1) % 4
    else:
        if dir == 0:
            now_r -= 1
            min_r = min(min_r, now_r)
        elif dir == 1:
            now_c -= 1
            min_c = min(min_c, now_c)
        elif dir == 2:
            now_r += 1
            max_r = max(max_r, now_r)
        else:
            now_c += 1
            max_c = max(max_c, now_c)
        maze[now_r][now_c] = True

for r in range(max_r, min_r - 1, -1):
    print("".join(["." if path else "#" for path in maze[r][min_c : max_c + 1]]))
