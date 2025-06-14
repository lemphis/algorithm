tc = int(input())
for _ in range(tc):
    s = input()
    map = {}
    idx = 0
    is_ok = True
    while idx < len(s):
        c = s[idx]
        if c in map:
            map[c] += 1
        else:
            map[c] = 1

        if map[c] == 3:
            if idx == len(s) - 1 or c != s[idx + 1]:
                is_ok = False
                break
            idx += 1
            map[c] = 0

        idx += 1

    print("OK" if is_ok else "FAKE")
