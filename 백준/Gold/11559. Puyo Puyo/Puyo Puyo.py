import sys
from collections import deque


def boom(field):
    is_boom = False
    for r in range(6):
        for c in range(12):
            if field[r][c] in ["R", "G", "B", "P", "Y"]:
                color = field[r][c]
                is_boom |= bfs(field, color, r, c)

    return is_boom


def bfs(field, color, r, c):
    is_boom = False
    dq = deque([(r, c)])
    field[r][c] = "."
    same_poses = [(r, c)]
    while dq:
        row, col = dq.popleft()
        dir = [(1, 0), (0, -1), (-1, 0), (0, 1)]
        for dr, dc in dir:
            nr, nc = row + dr, col + dc
            if 0 <= nr < 6 and 0 <= nc < 12 and field[nr][nc] == color:
                dq.append((nr, nc))
                field[nr][nc] = "."
                same_poses.append((nr, nc))
    if len(same_poses) < 4:
        for row, col in same_poses:
            field[row][col] = color
    else:
        is_boom = True

    return is_boom


def drop(field):
    for row in field:
        items = [item for item in row if item != "."]
        new_row = [0] * (12 - len(items)) + items
        row.clear()
        row.extend(new_row)


input = sys.stdin.readline

field = [deque(list(col)) for col in zip(*(list(input().strip()) for _ in range(12)))]

count = 0

while boom(field):
    drop(field)
    count += 1

print(count)
