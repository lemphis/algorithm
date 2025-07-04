N = int(input())
pillars = [tuple(map(int, input().split())) for _ in range(N)]
pillars.sort()
area = 0
max_height_l, max_h = max(pillars, key=lambda x: x[1])
before_max_idx = 0
for i in range(N):
    L, H = pillars[i]
    if pillars[before_max_idx][1] < H:
        area += pillars[before_max_idx][1] * (L - pillars[before_max_idx][0])
        before_max_idx = i
    if pillars[i][1] == max_h:
        break

before_max_idx = max_height_r = N - 1
for i in range(N - 1, -1, -1):
    L, H = pillars[i]
    if pillars[before_max_idx][1] < H:
        area += pillars[before_max_idx][1] * (pillars[before_max_idx][0] - L)
        before_max_idx = i
    if pillars[i][1] == max_h:
        max_height_r = L
        break

print(area + (max_height_r - max_height_l + 1) * max_h)
