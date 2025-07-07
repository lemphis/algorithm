import sys

input = sys.stdin.readline

sl, sr = input().split()
s = input().strip()

key_pos = {
    "q": (0, 0, False),
    "w": (0, 1, False),
    "e": (0, 2, False),
    "r": (0, 3, False),
    "t": (0, 4, False),
    "y": (0, 5, True),
    "u": (0, 6, True),
    "i": (0, 7, True),
    "o": (0, 8, True),
    "p": (0, 9, True),
    "a": (1, 0, False),
    "s": (1, 1, False),
    "d": (1, 2, False),
    "f": (1, 3, False),
    "g": (1, 4, False),
    "h": (1, 5, True),
    "j": (1, 6, True),
    "k": (1, 7, True),
    "l": (1, 8, True),
    "z": (2, 0, False),
    "x": (2, 1, False),
    "c": (2, 2, False),
    "v": (2, 3, False),
    "b": (2, 4, True),
    "n": (2, 5, True),
    "m": (2, 6, True),
}

ans = 0
for c in s:
    is_right_hand = key_pos[c][2]
    if is_right_hand:
        dist = abs(key_pos[c][0] - key_pos[sr][0]) + abs(key_pos[c][1] - key_pos[sr][1])
        ans += dist
        sr = c
    else:
        dist = abs(key_pos[c][0] - key_pos[sl][0]) + abs(key_pos[c][1] - key_pos[sl][1])
        ans += dist
        sl = c
    ans += 1

print(ans)
