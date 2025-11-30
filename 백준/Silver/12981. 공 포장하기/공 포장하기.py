R, G, B = map(int, input().split())

min_count = min(R, G, B)
ans = min_count
R -= min_count
G -= min_count
B -= min_count
ans += R // 3 + G // 3 + B // 3
R %= 3
G %= 3
B %= 3
if R == 2:
    ans += 1
    R = 0
if G == 2:
    ans += 1
    G = 0
if B == 2:
    ans += 1
    B = 0
if R + G + B > 0:
    ans += 1

print(ans)
