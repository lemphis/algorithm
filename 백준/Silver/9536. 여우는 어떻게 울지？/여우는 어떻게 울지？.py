import sys

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    sounds = input().split()
    cries = {}
    while (line := input().split())[0] != "what":
        sounds = [sound for sound in sounds if sound != line[2]]

    print(*sounds)
