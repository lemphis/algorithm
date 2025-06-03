N = int(input())
P = list(map(int, input().split()))
len, max_len = 0, 0
for i in range(1, N):
    if P[i] > P[i - 1]:
        len += P[i] - P[i - 1]
        max_len = max(max_len, len)
    else:
        len = 0

print(max_len)
