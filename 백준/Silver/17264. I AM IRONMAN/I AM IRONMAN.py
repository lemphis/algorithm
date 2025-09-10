import sys

input = sys.stdin.readline

N, P = map(int, input().split())
W, L, G = map(int, input().split())
matches = dict([tuple(input().split()) for _ in range(P)])
players = [input().strip() for _ in range(N)]

score = 0
level_up = False
for player in players:
    if player in matches and matches[player] == "W":
        score += W
    else:
        score = max(score - L, 0)
    if score >= G:
        level_up = True
        break

print("I AM NOT IRONMAN!!" if level_up else "I AM IRONMAN!!")
