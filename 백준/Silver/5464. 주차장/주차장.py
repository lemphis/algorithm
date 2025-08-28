import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())
prices = [int(input()) for _ in range(N)]
weights = [int(input()) for _ in range(M)]
orders = [abs(int(input())) - 1 for _ in range(M * 2)]

parking_lot = {num: -1 for num in range(N)}
total_price = 0
dq = deque()
for order in orders:
    out = False
    for pos, num in parking_lot.items():
        if order == num:
            total_price += prices[pos] * weights[order]
            parking_lot[pos] = dq.popleft() if dq else -1
            out = True

    if not out:
        parking = False
        for i in range(N):
            if parking_lot[i] == -1:
                parking_lot[i] = order
                parking = True
                break
        if not parking:
            dq.append(order)

print(total_price)
