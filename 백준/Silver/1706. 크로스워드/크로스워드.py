import sys

input = sys.stdin.readline

R, C = map(int, input().split())
map = [list(input().strip()) for _ in range(R)]

words = []
for row in map:
    for word in "".join(row).split("#"):
        if len(word) > 1:
            words.append(word)
for col in list(zip(*map)):
    for word in "".join(col).split("#"):
        if len(word) > 1:
            words.append(word)

words.sort()

print(words[0])
