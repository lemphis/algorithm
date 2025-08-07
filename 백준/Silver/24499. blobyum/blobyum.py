N, K = map(int, input().split())
apple_pie = list(map(int, input().split()))

sweet_sum = max_sum = sum(apple_pie[:K])
for i in range(K, N + K - 1):
    sweet_sum = sweet_sum - apple_pie[i - K] + apple_pie[i % N]
    if sweet_sum > max_sum:
        max_sum = sweet_sum

print(max_sum)
