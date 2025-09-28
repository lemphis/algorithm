import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
K = int(input())
apple_positions = set(
    (r - 1, c - 1) for r, c in (map(int, input().split()) for _ in range(K))
)
L = int(input())
turns = [
    (int(X), 1 if C == "D" else -1) for X, C in (input().split() for _ in range(L))
]

snake = deque([(0, 0)])
directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
direction = 0
lose = False
time = 0
turn_idx = 0
for turn_time, turn_dir in turns:
    for second in range(time, turn_time):
        time += 1
        next_direction = (
            snake[0][0] + directions[direction][0],
            snake[0][1] + directions[direction][1],
        )
        if (
            next_direction in snake
            or not 0 <= next_direction[0] < N
            or not 0 <= next_direction[1] < N
        ):
            lose = True
            break

        snake.appendleft(next_direction)
        if next_direction in apple_positions:
            apple_positions.remove(next_direction)
        else:
            snake.pop()

    if lose:
        break

    direction = (direction + turn_dir + 4) % 4

while not lose:
    time += 1
    next_direction = (
        snake[0][0] + directions[direction][0],
        snake[0][1] + directions[direction][1],
    )
    if (
        next_direction in snake
        or not 0 <= next_direction[0] < N
        or not 0 <= next_direction[1] < N
    ):
        lose = True
        break

    snake.appendleft(next_direction)
    if next_direction in apple_positions:
        apple_positions.remove(next_direction)
    else:
        snake.pop()

print(time)
