n = int(input())
origin_word = input()
origin_char_count = [0] * 26
for c in origin_word:
    origin_char_count[ord(c) - ord("A")] += 1

words = [input() for _ in range(n - 1)]
ans = 0
for word in words:
    if abs(len(origin_word) - len(word)) > 1:
        continue
    char_count = [0] * 26
    for c in word:
        char_count[ord(c) - ord("A")] += 1
    is_similar = True
    diff_count = 0
    for i in range(26):
        diff = abs(origin_char_count[i] - char_count[i])
        if diff > 1:
            is_similar = False
            break
        elif diff == 1:
            diff_count += 1
        if diff_count > 2:
            is_similar = False
            break
    if is_similar:
        ans += 1


print(ans)
