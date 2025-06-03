N, M = map(int, input().split())
castle = [list(input()) for _ in range(N)]

row_status, col_status = [False] * N, [False] * M
for r in range(N):
    for c in range(M):
        if castle[r][c] == "X":
            row_status[r] = True
            col_status[c] = True

print(max(N - sum(row_status), M - sum(col_status)))
