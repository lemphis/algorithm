N = int(input())
word_set = set()
for _ in range(N):
    word_set.add(str(sorted(input())))

print(len(word_set))
