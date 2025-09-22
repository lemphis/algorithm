import sys

input = sys.stdin.readline

while (pages := int(input())) > 0:
    is_print = [0] * (pages + 1)
    s = input().strip().split(",")
    for r in s:
        page = list(map(int, r.split("-")))
        if len(page) > 1:
            for i in range(max(1, page[0]), min(pages + 1, page[1] + 1)):
                is_print[i] = 1
        else:
            if page[0] <= pages:
                is_print[page[0]] = 1

    print(sum(is_print))
