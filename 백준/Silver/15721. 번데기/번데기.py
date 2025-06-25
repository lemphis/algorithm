A = int(input())
T = int(input())
chant = int(input())

idx = turn = count = 0
while True:
    arr = [0, 1] * 2 + [0] * (turn + 2) + [1] * (turn + 2)
    for num in arr:
        if num == chant:
            count += 1
            if count == T:
                print(idx % A)
                exit()
        idx += 1
    turn += 1
