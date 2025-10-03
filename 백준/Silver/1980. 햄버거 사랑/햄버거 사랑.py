n, m, t = map(int, input().split())

min_time = min(n, m)
max_time = max(n, m)
total_burger = t // min_time
total_coke = t % min_time

ans_burger = total_burger
ans_coke = total_coke
for _ in range(total_burger):
    total_burger -= 1
    total_coke += min_time
    if total_coke >= max_time:
        total_burger += 1
        total_coke -= max_time
    if ans_coke > total_coke:
        ans_burger = total_burger
        ans_coke = total_coke

print(ans_burger, ans_coke)
