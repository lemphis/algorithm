import sys

input = sys.stdin.readline

R, C = map(int, input().split())
old_map = [list(input().strip()) for _ in range(R)]
new_map = [row[:] for row in old_map]
dir = [(1, 0), (0, -1), (-1, 0), (0, 1)]
for r in range(R):
    for c in range(C):
        if old_map[r][c] == "X":
            count = 0
            for dr, dc in dir:
                next_r = r + dr
                next_c = c + dc
                if (
                    not (0 <= next_r < R and 0 <= next_c < C)
                    or old_map[next_r][next_c] == "."
                ):
                    count += 1
            if count > 2:
                new_map[r][c] = "."

start_r = start_c = end_r = end_c = 0
for r in range(R):
    if any(col_item == "X" for col_item in new_map[r]):
        start_r = r
        break
for c in range(C):
    if any(row_item == "X" for row_item in [row[c] for row in new_map]):
        start_c = c
        break
for r in range(R - 1, -1, -1):
    if any(col_item == "X" for col_item in new_map[r]):
        end_r = r + 1
        break
for c in range(C - 1, -1, -1):
    if any(row_item == "X" for row_item in [row[c] for row in new_map]):
        end_c = c + 1
        break

sliced = [row[start_c:end_c] for row in new_map[start_r:end_r]]

print(*["".join(row) for row in sliced], sep="\n")
