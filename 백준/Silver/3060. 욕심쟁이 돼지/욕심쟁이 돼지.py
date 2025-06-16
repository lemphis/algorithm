T = int(input())
for _ in range(T):
    N = int(input())
    total_feed = sum(map(int, input().split()))
    times = 1
    count = 1
    while total_feed * times <= N:
        times *= 4
        count += 1
    print(count)
