import sys

input = sys.stdin.readline

M, n = map(int, input().split())
dir = [(1, 0), (0, -1), (-1, 0), (0, 1)]
now_dir = 0
pos = [0, 0]
for _ in range(n):
    command, move_count = input().split()
    move_count = int(move_count)
    if command == "TURN":
        now_dir = (now_dir + (1 if move_count == 1 else -1) + 4) % 4
    else:
        pos[0] += dir[now_dir][0] * move_count
        pos[1] += dir[now_dir][1] * move_count
    if any(num not in range(M) for num in pos):
        print(-1)
        exit()

print(*pos)
