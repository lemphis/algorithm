N = int(input())
seats = input()
s_count, l_count = 0, 0
for seat in seats:
    if seat == "S":
        s_count += 1
    else:
        l_count += 1

print(N if l_count == 0 else s_count + (l_count // 2) + 1)
