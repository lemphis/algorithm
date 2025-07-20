import sys

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    n, k, t, m = map(int, input().split())
    scores = [
        {"score": [0] * k, "time": 0, "count": 0, "team": i + 1} for i in range(n)
    ]

    for time in range(m):
        i, j, s = map(int, input().split())
        if s > scores[i - 1]["score"][j - 1]:
            scores[i - 1]["score"][j - 1] = s
        scores[i - 1]["time"] = time
        scores[i - 1]["count"] += 1

    scores.sort(key=lambda x: (-sum(x["score"]), x["count"], x["time"]))

    for rank, info in enumerate(scores, start=1):
        if info["team"] == t:
            print(rank)
            break
