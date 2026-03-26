import sys

input = sys.stdin.readline

N = input().strip()

l = len(N)
new_n = None

if all(c == "9" for c in N):
    new_n = "1" + "0" * (l - 1) + "1"
else:
    if l & 1:
        left = N[: l // 2 + 1]
        new_n = left + left[:-1][::-1]
        if new_n <= N:
            left = str(int(left) + 1)
            new_n = left + left[:-1][::-1]
    else:
        left = N[: l // 2]
        new_n = left + left[::-1]
        if new_n <= N:
            left = str(int(left) + 1)
            new_n = left + left[::-1]

print(new_n)
