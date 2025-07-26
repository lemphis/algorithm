import sys

input = sys.stdin.readline

N, M = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]
dir = [(0, -1), (-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1)]
diagonal_dir = [(-1, -1), (-1, 1), (1, -1), (1, 1)]

clouds = [(N - 2, 0), (N - 1, 0), (N - 2, 1), (N - 1, 1)]
for _ in range(M):
    d, s = map(int, input().split())
    d -= 1
    move = s % N
    visited = [[False] * N for _ in range(N)]
    for i in range(len(clouds)):
        c_r, c_c = clouds[i]
        nr, nc = (c_r + dir[d][0] * move + N) % N, (c_c + dir[d][1] * move + N) % N
        clouds[i] = nr, nc
        A[nr][nc] += 1
        visited[nr][nc] = True

    for c_r, c_c in clouds:
        bucket_count = 0
        for d_r, d_c in diagonal_dir:
            nr, nc = c_r + d_r, c_c + d_c
            if 0 <= nr < N and 0 <= nc < N and A[nr][nc] > 0:
                bucket_count += 1
        A[c_r][c_c] += bucket_count

    clouds = [
        (r, c) for r in range(N) for c in range(N) if A[r][c] > 1 and not visited[r][c]
    ]
    for c_r, c_c in clouds:
        A[c_r][c_c] -= 2

print(sum(count for row in A for count in row))
