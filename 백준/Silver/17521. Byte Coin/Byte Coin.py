n, W = map(int, input().split())
coin = 0
before_price = 50
for _ in range(n):
    s = int(input())
    if s > before_price and coin == 0:
        coin = W // before_price
        W %= before_price
    elif s < before_price and coin > 0:
        W += coin * before_price
        coin = 0
    before_price = s

print(W + coin * before_price)
