N = int(input())
amounts = [tuple(map(int, input().split("/"))) for _ in range(N)]

quarter = 0
three_quarters = 0
half = 0
for numerator, denominator in amounts:
    if denominator == 2:
        half += 1
    elif numerator == 1:
        quarter += 1
    else:
        three_quarters += 1

pizza = half // 2
half_remainder = half % 2

min_quarter = min(quarter, three_quarters)
pizza += min_quarter
quarter -= min_quarter
three_quarters -= min_quarter

pizza += three_quarters

if half_remainder == 1:
    pizza += 1
    if quarter >= 2:
        quarter -= 2
    else:
        quarter = 0

pizza += quarter // 4
if quarter % 4 > 0:
    pizza += 1

print(pizza)
