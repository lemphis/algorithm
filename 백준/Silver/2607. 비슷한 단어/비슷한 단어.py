n = int(input())
origin_word = input()
origin_count = [0] * 26
for c in origin_word:
    origin_count[ord(c) - ord("A")] += 1

ans = 0
for _ in range(n - 1):
    word = input()
    char_count = [0] * 26
    for c in word:
        char_count[ord(c) - ord("A")] += 1
    plus = sum(max(origin_count[i] - char_count[i], 0) for i in range(26))
    minus = sum(max(char_count[i] - origin_count[i], 0) for i in range(26))
    if plus <= 1 and minus <= 1:
        ans += 1

print(ans)
