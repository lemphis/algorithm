import sys

input = sys.stdin.readline

N = int(input())
matrix = [list(map(int, input().split())) for _ in range(N)]

if N == 2:
    print("1 1")
else:
    A = []
    A.append((matrix[0][1] + matrix[0][2] - matrix[1][2]) // 2)
    for i in range(1, N):
        A.append(matrix[0][i] - A[0])

    print(*A, sep=" ")
