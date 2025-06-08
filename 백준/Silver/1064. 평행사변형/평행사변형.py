xa, ya, xb, yb, xc, yc = map(int, input().split())
ab = ((xa - xb) ** 2 + (ya - yb) ** 2) ** 0.5
bc = ((xb - xc) ** 2 + (yb - yc) ** 2) ** 0.5
ca = ((xc - xa) ** 2 + (yc - ya) ** 2) ** 0.5
if (xb - xa) * (yc - ya) - (yb - ya) * (xc - xa) == 0:
    print(-1)
else:
    arr = sorted([ab, bc, ca])
    print((arr[1] * 2 + arr[2] * 2) - (arr[0] * 2 + arr[1] * 2))
