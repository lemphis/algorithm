import sys

input = sys.stdin.readline

N, M = map(int, input().split())
orders = []
for _ in range(N):
    query = input().split()
    if query[0] == "order":
        n, t = int(query[1]), int(query[2])
        orders.append((n, t))
    elif query[0] == "complete":
        n = int(query[1])
        orders = [order for order in orders if order[0] != n]
    else:
        orders.sort(key=lambda x: (x[1], x[0]))

    if orders:
        print(*[order[0] for order in orders], sep=" ")
    else:
        print("sleep")
