import sys

input = sys.stdin.readline

N = int(input())
prices = [list(map(int, input().split())) for _ in range(N)]

max_profit = 0
min_price = 0
for i in range(N):
    std = prices[i][0]
    profit = 0
    for price, fee in prices:
        if price >= std > fee:
            profit += std - fee
    if profit > max_profit or (profit == max_profit and std < min_price):
        max_profit = profit
        min_price = std

print(min_price)
