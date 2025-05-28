T = int(input())
for _ in range(T):
    C = int(input())
    q = C // 25
    C %= 25
    d = C // 10
    C %= 10
    n = C // 5
    C %= 5
    print(q, d, n, C)
