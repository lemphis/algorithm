import sys

input = sys.stdin.readline

cryptogram = input().strip()
N = int(input())
words = [input().strip() for _ in range(N)]

std = ord("a")
for d in range(26):
    ans = []
    for c in cryptogram:
        encrypted_c = chr(std + (ord(c) + d - std) % 26)
        ans.append(encrypted_c)
    joined_ans = "".join(ans)
    for word in words:
        if joined_ans.find(word) > -1:
            print(joined_ans)
            exit()
