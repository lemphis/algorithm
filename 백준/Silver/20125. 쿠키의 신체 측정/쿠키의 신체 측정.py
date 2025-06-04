N = int(input())
board = [list(input()) for _ in range(N)]
heart = (0, 0)
for r in range(1, N - 2):
    found = False
    for c in range(1, N - 1):
        if (
            board[r + 1][c]
            == board[r][c + 1]
            == board[r - 1][c]
            == board[r][c - 1]
            == "*"
        ):
            found = True
            heart = (r, c)
            break
    if found:
        break

head = heart[0]
for r in range(0, heart[0]):
    if board[r][heart[1]] == "*":
        head = heart[0] - r
        break

left_hand = heart[1]
for c in range(0, heart[1]):
    if board[heart[0]][c] == "*":
        left_hand = heart[1] - c
        break

right_hand = N - heart[1] - 1
for c in range(heart[1] + 1, N):
    if board[heart[0]][c] == "_":
        right_hand = c - heart[1] - 1
        break

waist = 0
waist_row = 0
for r in range(heart[0] + 1, N):
    if board[r][heart[1]] == "_":
        waist = r - heart[0] - 1
        waist_row = r - 1
        break

left_leg = N - 1 - waist_row
for r in range(waist_row + 1, N):
    if board[r][heart[1] - 1] == "_":
        left_leg = r - waist_row - 1
        break

right_leg = N - 1 - waist_row
for r in range(waist_row + 1, N):
    if board[r][heart[1] + 1] == "_":
        right_leg = r - waist_row - 1
        break

print(heart[0] + 1, heart[1] + 1)
print(left_hand, right_hand, waist, left_leg, right_leg)
