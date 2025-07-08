T = int(input())

for _ in range(T):
    num = input()
    count = 0
    while num != "6174":
        min_num = int("".join(sorted(num)))
        max_num = int("".join(sorted(num, reverse=True)))
        num = str(max_num - min_num).zfill(4)
        count += 1

    print(count)
