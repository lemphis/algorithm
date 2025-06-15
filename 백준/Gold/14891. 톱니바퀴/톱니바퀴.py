gears = [input() for _ in range(4)]
K = int(input())
for _ in range(K):
    gear_num, dir = map(int, input().split())
    idx = gear_num - 1
    move_dirs = [0] * 4
    move_dirs[idx] = dir

    for i in range(idx - 1, -1, -1):
        if gears[i + 1][6] == gears[i][2]:
            break
        move_dirs[i] = 1 if move_dirs[i + 1] == -1 else -1
    for i in range(idx + 1, 4):
        if gears[i - 1][2] == gears[i][6]:
            break
        move_dirs[i] = 1 if move_dirs[i - 1] == -1 else -1

    for i in range(4):
        if move_dirs[i] == 1:
            gears[i] = gears[i][-1] + gears[i][:-1]
        elif move_dirs[i] == -1:
            gears[i] = gears[i][1:] + gears[i][0]

print(sum(1 << i for i in range(4) if gears[i][0] == "1"))
