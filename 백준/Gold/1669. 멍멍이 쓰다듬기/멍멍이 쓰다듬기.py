import sys

input = sys.stdin.readline

X, Y = map(int, input().split())

diff = Y - X

if diff == 0:
    print(0)
else:
    day = 1
    while True:
        if day & 1:
            count = ((day + 1) // 2) ** 2
        else:
            count = (day // 2) * (day // 2 + 1)

        if diff <= count:
            print(day)
            break

        day += 1
