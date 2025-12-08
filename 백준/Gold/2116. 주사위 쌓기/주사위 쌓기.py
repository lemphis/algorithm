import sys

input = sys.stdin.readline

n = int(input())
dices = [list(map(int, input().split())) for _ in range(n)]

opposite_idx = {0: 5, 1: 3, 2: 4, 3: 1, 4: 2, 5: 0}

max_sum = 0
for top_idx in range(6):
    top_num = dices[0][top_idx]
    total = max(
        [
            dices[0][i]
            for i in range(6)
            if dices[0][i] not in [dices[0][top_idx], dices[0][opposite_idx[top_idx]]]
        ]
    )
    for i in range(1, n):
        dice = dices[i]
        bottom_idx = dice.index(top_num)
        top_num = dice[opposite_idx[bottom_idx]]
        total += max([num for num in dice if num not in [top_num, dice[bottom_idx]]])

    max_sum = max(max_sum, total)

print(max_sum)
