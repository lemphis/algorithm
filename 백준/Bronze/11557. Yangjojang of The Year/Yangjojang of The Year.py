T = int(input())
for _ in range(T):
    name, count = "", 0
    N = int(input())
    for _ in range(N):
        S, L = input().split()
        L = int(L)
        if L > count:
            name = S
            count = L
    print(name)
