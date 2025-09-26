import sys

input = sys.stdin.readline

R, C = map(int, input().split())
puzzle = [input().strip() for _ in range(R)]

words = []
for row in puzzle:
    for word in row.split("#"):
        if len(word) > 1:
            words.append(word)
for col in ["".join(row[i] for row in puzzle) for i in range(C)]:
    for word in str(col).split("#"):
        if len(word) > 1:
            words.append(word)

words.sort()

print(words[0])
