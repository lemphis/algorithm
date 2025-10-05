import sys
from collections import deque

input = sys.stdin.readline


def fill_water(maps, R, C, water_poses):
    new_poses = []
    for r, c in water_poses:
        for dr, dc in dir:
            nr, nc = r + dr, c + dc
            if 0 <= nr < R and 0 <= nc < C and maps[nr][nc] == ".":
                maps[nr][nc] = "*"
                new_poses.append((nr, nc))
    return new_poses


R, C = map(int, input().split())
maps = [list(input().strip()) for _ in range(R)]

beaver = (0, 0)
hedgehog = (0, 0)
for r in range(R):
    for c in range(C):
        if maps[r][c] == "D":
            beaver = (r, c)
        elif maps[r][c] == "S":
            hedgehog = (r, c)

dir = [(1, 0), (0, -1), (-1, 0), (0, 1)]
dq = deque([hedgehog])
find = False
minute = 0
visited = [[False] * C for _ in range(R)]
visited[hedgehog[0]][hedgehog[1]] = True
water_poses = [(r, c) for r in range(R) for c in range(C) if maps[r][c] == "*"]
while dq:
    water_poses = fill_water(maps, R, C, water_poses)
    for _ in range(len(dq)):
        r, c = dq.popleft()
        if (r, c) == beaver:
            find = True
            break
        for dr, dc in dir:
            nr, nc = r + dr, c + dc
            if (
                0 <= nr < R
                and 0 <= nc < C
                and not visited[nr][nc]
                and maps[nr][nc] in [".", "D"]
            ):
                dq.append((nr, nc))
                visited[nr][nc] = True

    if find:
        break

    minute += 1

print(minute if find else "KAKTUS")
