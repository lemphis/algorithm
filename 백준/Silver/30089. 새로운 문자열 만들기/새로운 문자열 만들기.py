import sys

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    S = input().strip()
    new_s = S
    for i in range(len(S)):
        new_s = S + "".join(S[:i][::-1])
        if new_s == new_s[::-1]:
            print(new_s)
            break
