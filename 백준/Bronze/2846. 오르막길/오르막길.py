N = int(input())
P = list(map(int, input().split()))
before = P[0]
len, max_len = 0, 0
for num in P[1:]:
    if num > before:
        len += num - before
        max_len = max(max_len, len)
    else:
        len = 0
    before = num

print(max_len)
