import sys

input = sys.stdin.readline

SCISSORS = 1
ROCK = 2
PAPER = 3

N = int(input())
ace = list(map(int, input().split()))
daniel = list(map(int, input().split()))

ace_max = 0
ace_count = 0
daniel_max = 0
daniel_count = 0
for i in range(N):
    if (
        (ace[i] == SCISSORS and daniel[i] == PAPER)
        or (ace[i] == PAPER and daniel[i] == ROCK)
        or (ace[i] == ROCK and daniel[i] == SCISSORS)
    ):
        daniel_count = 0
        ace_count += 1
        ace_max = max(ace_max, ace_count)
    elif (
        (daniel[i] == SCISSORS and ace[i] == PAPER)
        or (daniel[i] == PAPER and ace[i] == ROCK)
        or (daniel[i] == ROCK and ace[i] == SCISSORS)
    ):
        ace_count = 0
        daniel_count += 1
        daniel_max = max(daniel_max, daniel_count)
    else:
        if daniel_count == 0:
            daniel_count += 1
            ace_count = 0
        else:
            ace_count += 1
            daniel_count = 0

    ace_max = max(ace_max, ace_count)
    daniel_max = max(daniel_max, daniel_count)

print(max(ace_max, daniel_max))
