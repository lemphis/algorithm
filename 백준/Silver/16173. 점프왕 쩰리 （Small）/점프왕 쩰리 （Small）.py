from collections import deque

N = int(input())
map = [list(map(int, input().split())) for _ in range(N)]

q = deque()
q.append((0, 0))
arrived = False
while q:
    r, c = q.popleft()
    if r == c == N - 1:
        arrived = True
        break
    next_r, next_c = r + map[r][c], c + map[r][c]
    if next_r >= 0 and next_r < N and map[next_r][c] != 0:
        q.append((next_r, c))
    if next_c >= 0 and next_c < N and map[r][next_c] != 0:
        q.append((r, next_c))

print("HaruHaru" if arrived else "Hing")
