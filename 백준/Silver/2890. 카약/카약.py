R, C = map(int, input().split())
scores = []
for _ in range(R):
    lane = input()[1:-1]
    team = idx = -1
    for c, char in enumerate(lane):
        if char.isdigit():
            team = int(char)
            idx = c
            break
    if idx > -1:
        scores.append((-idx, team - 1))

scores.sort()

rank = 1
before_score = scores[0][0]
ans = [0] * 9
for score, i in scores:
    if score == before_score:
        ans[i] = rank
    else:
        rank += 1
        ans[i] = rank
    before_score = score

print(*ans, sep="\n")
