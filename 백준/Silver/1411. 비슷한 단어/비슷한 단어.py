import sys

input = sys.stdin.readline


def convert(word):
    m = {}
    idx = 0
    new_word = []
    for c in word:
        if c not in m:
            m[c] = idx
            idx += 1
        new_word.append(str(m[c]))

    return "".join(new_word)


N = int(input())
words = [input().strip() for _ in range(N)]

new_words = [convert(word) for word in words]
pair_count = 0
for i in range(N - 1):
    for j in range(i + 1, N):
        if new_words[i] == new_words[j]:
            pair_count += 1

print(pair_count)
