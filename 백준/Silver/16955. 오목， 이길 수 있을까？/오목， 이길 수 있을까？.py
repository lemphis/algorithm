import sys

input = sys.stdin.readline

board = [list(input().strip()) for _ in range(10)]

for i in range(10):
    for j in range(10):
        if board[i][j] == ".":
            board[i][j] = "X"
            for r in range(10):
                for c in range(10):
                    if c <= 5:
                        row = board[r][c : c + 5]
                        if all([item == "X" for item in row]):
                            print(1)
                            exit()
                    if r <= 5:
                        col = [board[i][c] for i in range(r, r + 5)]
                        if all([item == "X" for item in col]):
                            print(1)
                            exit()
                    if r <= 5 and c <= 5:
                        diagonal = [board[r + k][c + k] for k in range(5)]
                        if all([item == "X" for item in diagonal]):
                            print(1)
                            exit()
                    if r <= 5 and c >= 4:
                        diagonal = [board[r + k][c - k] for k in range(5)]
                        if all([item == "X" for item in diagonal]):
                            print(1)
                            exit()
            board[i][j] = "."

print(0)
