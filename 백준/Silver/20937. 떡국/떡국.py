N = int(input())
c = list(map(int, input().split()))

counts = [0] * 50_000
max_count = 0
for num in c:
    counts[num - 1] += 1
    if counts[num - 1] > max_count:
        max_count = counts[num - 1]

print(max_count)
