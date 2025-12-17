import sys

input = sys.stdin.readline

N, M, R = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

layer = min(N, M) // 2
new_arr = [[0] * M for _ in range(N)]
for i in range(layer):
    line = []
    for r in range(i, N - 1 - i):
        line.append(arr[r][i])
    for c in range(i, M - 1 - i):
        line.append(arr[N - 1 - i][c])
    for r in range(N - 1 - i, i, -1):
        line.append(arr[r][M - 1 - i])
    for c in range(M - 1 - i, i, -1):
        line.append(arr[i][c])

    perimeter = len(line)
    line = line[-(R % perimeter) :] + line[: -(R % perimeter)]
    idx = 0
    for r in range(i, N - 1 - i):
        new_arr[r][i] = line[idx]
        idx += 1
    for c in range(i, M - 1 - i):
        new_arr[N - 1 - i][c] = line[idx]
        idx += 1
    for r in range(N - 1 - i, i, -1):
        new_arr[r][M - 1 - i] = line[idx]
        idx += 1
    for c in range(M - 1 - i, i, -1):
        new_arr[i][c] = line[idx]
        idx += 1

print(*[" ".join(map(str, row)) for row in new_arr], sep="\n")
