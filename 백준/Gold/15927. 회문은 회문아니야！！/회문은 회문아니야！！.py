import sys

input = sys.stdin.readline

s = input().strip()

if all(c == s[0] for c in s):
    print(-1)
    exit()

l = len(s)
if s != s[::-1]:
    print(l)
else:
    print(l - 1)
