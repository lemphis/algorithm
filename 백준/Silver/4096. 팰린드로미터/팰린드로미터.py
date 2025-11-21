import sys

input = sys.stdin.readline

while (n := input().strip()) != "0":
    count = 0
    while n != n[::-1]:
        n = str(int(n) + 1).rjust(len(n), "0")
        count += 1

    print(count)
