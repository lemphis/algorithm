import sys

input = sys.stdin.readline


def dfs(l, depth, w, freq):
    if l == depth:
        print(w)
        return

    for k, v in freq.items():
        if v > 0:
            freq[k] -= 1
            dfs(l, depth + 1, w + k, freq)
            freq[k] += 1


N = int(input())
for _ in range(N):
    word = list(input().strip())

    word.sort()

    freq = {}
    for c in word:
        freq[c] = freq.get(c, 0) + 1

    dfs(len(word), 0, "", freq)
