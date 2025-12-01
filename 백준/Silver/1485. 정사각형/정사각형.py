import sys

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    poses = [tuple(map(int, input().split())) for _ in range(4)]
    lens = [
        (poses[0][0] - poses[i][0]) ** 2 + (poses[0][1] - poses[i][1]) ** 2
        for i in range(1, 4)
    ]
    lens.sort()
    if lens[0] != lens[1]:
        print(0)
        continue

    is_square = True
    for i in range(1, 3):
        temp = [
            (poses[i][0] - poses[j][0]) ** 2 + (poses[i][1] - poses[j][1]) ** 2
            for j in range(4)
            if i != j
        ]
        temp.sort()
        if lens != temp:
            is_square = False
            break

    print(1 if is_square else 0)
