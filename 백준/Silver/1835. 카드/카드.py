from collections import deque

N = int(input())

cards = deque([N])
for i in range(N - 1, 0, -1):
    cards.appendleft(i)
    cards.rotate(i)

print(*cards)
