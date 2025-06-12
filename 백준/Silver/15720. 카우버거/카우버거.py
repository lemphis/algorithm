B, C, D = map(int, input().split())
burgers = sorted(list(map(int, input().split())), reverse=True)
sides = sorted(list(map(int, input().split())), reverse=True)
drinks = sorted(list(map(int, input().split())), reverse=True)

min_num = min(B, C, D)
origin_price = 0
discount_price = 0
for i in range(min_num):
    set_sum = burgers[i] + sides[i] + drinks[i]
    origin_price += set_sum
    discount_price += set_sum * 0.9
rest_price = sum(burgers[min_num:]) + sum(sides[min_num:]) + sum(drinks[min_num:])

print(origin_price + rest_price)
print(int(discount_price) + rest_price)