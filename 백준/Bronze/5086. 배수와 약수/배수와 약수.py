import sys

lines = sys.stdin.readlines()
for line in lines:
    a, b = map(int, line.split())
    if a == b == 0:
        break

    if b % a == 0:
        print("factor")
    elif a % b == 0:
        print("multiple")
    else:
        print("neither")
