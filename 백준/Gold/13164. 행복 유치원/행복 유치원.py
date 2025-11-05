N, K = map(int, input().split())
heights = list(map(int, input().split()))

diffs = [heights[i] - heights[i - 1] for i in range(1, N)]
diffs.sort(reverse=True)

print(sum(diffs[K - 1 :]))
