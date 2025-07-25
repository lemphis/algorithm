sound = input()

quack = "quack"
stage_count = [0] * 5
duck_count = 0

for c in sound:
    idx = quack.find(c)
    if idx < 0:
        print(-1)
        exit()

    if idx == 0:
        if stage_count[4] > 0:
            stage_count[4] -= 1
        else:
            duck_count += 1
        stage_count[0] += 1
    else:
        if stage_count[idx - 1] == 0:
            print(-1)
            exit()
        stage_count[idx - 1] -= 1
        stage_count[idx] += 1

if any(stage_count[i] != 0 for i in range(4)):
    print(-1)
else:
    print(duck_count)
