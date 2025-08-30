import sys

input = sys.stdin.readline

tc = int(input())
for i in range(tc):
    board = [list(map(int, input().split())) for _ in range(9)]
    correct = True
    for row in board:
        if len(set(row)) < 9:
            correct = False
            break
    if correct:
        for c in range(9):
            s = set()
            for r in range(9):
                s.add(board[r][c])
            if len(set(s)) < 9:
                correct = False
                break
    if correct:
        for j in range(3):
            for k in range(3):
                s = set()
                for r in range(3):
                    for c in range(3):
                        s.add(board[j * 3 + r][k * 3 + c])
            if len(set(s)) < 9:
                correct = False
                break

    if correct:
        print(f"Case {i+1}: CORRECT")
    else:
        print(f"Case {i+1}: INCORRECT")
    input()
