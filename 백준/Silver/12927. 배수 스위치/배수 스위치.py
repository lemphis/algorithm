import sys

input = sys.stdin.readline

bulbs = ["N"] + list(input().strip())
count = 0
n = len(bulbs)
for i in range(1, n):
    if bulbs[i] == "Y":
        times = 1
        while i * times < n:
            bulbs[i * times] = "N" if bulbs[i * times] == "Y" else "Y"
            times += 1
        count += 1

print(count)
