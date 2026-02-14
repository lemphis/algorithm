import sys

input = sys.stdin.readline

N = int(input())
words = [input().strip() for _ in range(N)]

m = {}
for word in words:
    digit = 1
    for c in word[::-1]:
        m[c] = m.get(c, 0) + digit
        digit *= 10

ranks = [(int(v), k) for k, v in m.items()]
ranks.sort(reverse=True)

next_num = 9
ans = 0
for n, c in ranks:
    ans += n * next_num
    next_num -= 1

print(ans)
