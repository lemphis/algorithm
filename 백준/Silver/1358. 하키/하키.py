W, H, X, Y, P = map(int, input().split())
count = 0
radius = H // 2
for _ in range(P):
    x, y = map(int, input().split())
    l_dist = (y - (Y + radius)) ** 2 + (x - X) ** 2
    r_dist = (y - (Y + radius)) ** 2 + (x - (X + W)) ** 2
    if (
        l_dist <= radius**2
        or r_dist <= radius**2
        or (X <= x <= X + W and Y <= y <= Y + H)
    ):
        count += 1

print(count)
