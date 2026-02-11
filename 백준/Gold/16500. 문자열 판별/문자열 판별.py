import sys

input = sys.stdin.readline

S = input().strip()
N = int(input())
words = [input().strip() for _ in range(N)]

l = len(S)
dp = [False] * (l + 1)
dp[0] = True

for i in range(1, l + 1):
    for j in range(N):
        word_len = len(words[j])
        if i >= word_len and dp[i - word_len] and S[i - word_len : i] == words[j]:
            dp[i] = True
            break

print(1 if dp[l] else 0)
