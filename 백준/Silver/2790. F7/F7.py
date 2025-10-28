N = int(input())
scores = [int(input()) for _ in range(N)]

scores.sort()

threshold = max([N - i + scores[i] for i in range(N)])
count = 1
for score in scores[: N - 1]:
    if score + N >= threshold:
        count += 1

print(count)
