S = input()
ans = ""
for c in S:
    if not c.isalpha():
        ans += c
    else:
        if c.isupper():
            ans += chr((ord(c) + 13 - ord("A")) % 26 + ord("A"))
        else:
            ans += chr((ord(c) + 13 - ord("a")) % 26 + ord("a"))

print(ans)
