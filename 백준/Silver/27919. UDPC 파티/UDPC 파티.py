V = list(input().strip())

u_count = c_count = d_count = p_count = 0
for c in V:
    if c == "U":
        u_count += 1
    elif c == "D":
        d_count += 1
    elif c == "P":
        p_count += 1
    else:
        c_count += 1

result = []
if u_count + c_count > 0:
    if u_count + c_count > (d_count + p_count + 1) // 2:
        result.append("U")
if d_count + p_count > 0:
    result.append("D")
    result.append("P")

print("".join(result))
