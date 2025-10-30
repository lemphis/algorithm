N = int(input())
s, g, p, d = map(int, input().split())
tiers = list(input().strip())

max_req = {"B": s - 1, "S": g - 1, "G": p - 1, "P": d - 1, "D": d}
max_req = {"B": s, "S": g, "G": p, "P": d}
prev = 0
ans = 0
for tier in tiers:
    if tier == "D":
        ans += d
        prev = d
    else:
        ans += max_req[tier] - prev - 1
        prev = max_req[tier] - prev - 1

print(ans)
