import sys

input = sys.stdin.readline

N, M = map(int, input().split())
board = [list(input().strip()) for _ in range(N)]

min_r = N
min_c = M
max_r = max_c = 0
for r in range(N):
    for c in range(M):
        if board[r][c] == "#":
            min_r = min(min_r, r)
            max_r = max(max_r, r)
            min_c = min(min_c, c)
            max_c = max(max_c, c)

center_r = (min_r + max_r) // 2
center_c = (min_c + max_c) // 2

if board[min_r][center_c] == ".":
    print("UP")
elif board[max_r][center_c] == ".":
    print("DOWN")
elif board[center_r][min_c] == ".":
    print("LEFT")
elif board[center_r][max_c] == ".":
    print("RIGHT")
