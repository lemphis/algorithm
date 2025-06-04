N = input()
seats = input()
s_count, l_count = 0, 0
for seat in seats:
    if seat == "S":
        s_count += 1
    else:
        l_count += 1

if l_count == 0:
    print(N)
elif s_count == 0:
    print(N - 1)
else:
    print(s_count + (l_count // 2) + 1)
