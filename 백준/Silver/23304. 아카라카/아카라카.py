def check(s):
    global is_akaraka

    if len(s) == 1:
        return

    mid = len(s) // 2
    left = s[:mid]
    right = s[mid + 1 :] if len(s) & 1 else s[mid:]

    if left != right[::-1]:
        is_akaraka = False
        return

    check(left)
    check(right)


S = input().strip()

is_akaraka = True
check(S)

print("AKARAKA" if is_akaraka else "IPSELENTI")
