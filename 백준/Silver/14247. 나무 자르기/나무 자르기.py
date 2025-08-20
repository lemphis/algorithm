n = int(input())
H = list(map(int, input().split()))
A = list(map(int, input().split()))

total_height = 0
trees = list(zip(H, A))
trees.sort(key=lambda x: x[1])
for day, (h, a) in enumerate(trees):
    total_height += h + a * day

print(total_height)
