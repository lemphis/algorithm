import sys

input = sys.stdin.readline


def count_wins(board, player):
    lines = [
        (0, 1, 2),
        (3, 4, 5),
        (6, 7, 8),
        (0, 3, 6),
        (1, 4, 7),
        (2, 5, 8),
        (0, 4, 8),
        (2, 4, 6),
    ]
    return sum(board[a] == board[b] == board[c] == player for a, b, c in lines)


while (line := input().strip()) != "end":
    x_count = line.count("X")
    o_count = line.count("O")
    if o_count != x_count and o_count + 1 != x_count:
        print("invalid")
        continue

    x_win_count = count_wins(line, "X")
    o_win_count = count_wins(line, "O")

    if x_win_count > 0 and x_count != o_count + 1:
        print("invalid")
        continue

    if o_win_count > 0 and x_count != o_count:
        print("invalid")
        continue

    if x_win_count > 0 and o_win_count > 0:
        print("invalid")
        continue

    if x_win_count == 0 and o_win_count == 0 and x_count + o_count < 9:
        print("invalid")
        continue

    print("valid")
