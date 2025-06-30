K = int(input())
field = [tuple(map(int, input().split())) for _ in range(6)]
max_w = max_h = 0
idx_w = idx_h = -1
for i, (d, l) in enumerate(field):
    if d in (1, 2):
        if max_w < l:
            max_w, idx_w = l, i
    else:
        if max_h < l:
            max_h, idx_h = l, i

print(((max_w * max_h) - (field[(idx_w + 3) % 6][1] * field[(idx_h + 3) % 6][1])) * K)
