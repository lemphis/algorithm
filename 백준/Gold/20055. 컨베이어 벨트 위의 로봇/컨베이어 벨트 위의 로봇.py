from collections import deque

N, K = map(int, input().split())
durabilities = deque(list(map(int, input().split())))
robots = deque([False] * N)
count = 0
while True:
    if sum(1 for num in durabilities if num == 0) >= K:
        break
    last_durability = durabilities.pop()
    durabilities.appendleft(last_durability)
    robots.pop()
    robots.appendleft(False)
    robots[N - 1] = False
    for i in range(N - 2, -1, -1):
        if durabilities[i + 1] > 0 and robots[i] and not robots[i + 1]:
            robots[i + 1] = True
            robots[i] = False
            durabilities[i + 1] -= 1
    robots[N - 1] = False
    if durabilities[0] > 0:
        robots[0] = True
        durabilities[0] -= 1
    count += 1

print(count)
