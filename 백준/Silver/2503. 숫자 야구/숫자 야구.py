N = int(input())
items = [tuple(map(int, input().split())) for _ in range(N)]
ans = 0
for num in range(123, 988):
    s_num = str(num)
    if "0" in s_num or len(set(s_num)) != 3:
        continue

    count = 0
    for q, s, b in items:
        s_q = str(q)
        for i in range(3):
            if s_num[i] == s_q[i]:
                s -= 1
            elif s_num[i] != s_q[i] and s_num[i] in s_q:
                b -= 1
        if s == 0 and b == 0:
            count += 1
    if count == N:
        ans += 1

print(ans)
