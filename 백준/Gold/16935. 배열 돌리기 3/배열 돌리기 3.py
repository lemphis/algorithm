import sys

input = sys.stdin.readline


def op1(arr):
    return list(reversed(arr))


def op2(arr):
    return [list(reversed(row)) for row in arr]


def op3(arr, row, col):
    new_arr = [[0] * row for _ in range(col)]
    for r in range(row):
        for c in range(col):
            new_arr[c][row - 1 - r] = arr[r][c]

    return new_arr


def op4(arr, row, col):
    new_arr = [[0] * row for _ in range(col)]
    for r in range(row):
        for c in range(col):
            new_arr[col - 1 - c][r] = arr[r][c]

    return new_arr


def op5(arr, row, col):
    half_r = row // 2
    half_c = col // 2
    new_arr = [[0] * col for _ in range(row)]
    for r in range(half_r):
        for c in range(half_c):
            new_arr[r][c + half_c] = arr[r][c]
    for r in range(half_r):
        for c in range(half_c, col):
            new_arr[r + half_r][c] = arr[r][c]
    for r in range(half_r, row):
        for c in range(half_c, col):
            new_arr[r][c - half_c] = arr[r][c]
    for r in range(half_r, row):
        for c in range(half_c):
            new_arr[r - half_r][c] = arr[r][c]

    return new_arr


def op6(arr, row, col):
    half_r = row // 2
    half_c = col // 2
    new_arr = [[0] * col for _ in range(row)]
    for r in range(half_r):
        for c in range(half_c):
            new_arr[r + half_r][c] = arr[r][c]
    for r in range(half_r, row):
        for c in range(half_c):
            new_arr[r][c + half_c] = arr[r][c]
    for r in range(half_r, row):
        for c in range(half_c, col):
            new_arr[r - half_r][c] = arr[r][c]
    for r in range(half_r):
        for c in range(half_c, col):
            new_arr[r][c - half_c] = arr[r][c]

    return new_arr


N, M, R = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]
ops = list(map(int, input().split()))

for op in ops:
    r = len(A)
    c = len(A[0])
    if op == 1:
        A = op1(A)
    elif op == 2:
        A = op2(A)
    elif op == 3:
        A = op3(A, r, c)
    elif op == 4:
        A = op4(A, r, c)
    elif op == 5:
        A = op5(A, r, c)
    elif op == 6:
        A = op6(A, r, c)

for row in A:
    print(*row)
