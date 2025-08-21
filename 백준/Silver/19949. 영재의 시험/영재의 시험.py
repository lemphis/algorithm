def dfs(ans, submit, depth, ans_count):
    global count

    if depth == 10:
        if ans_count > 4:
            count += 1
        return
    for i in range(1, 6):
        if depth > 1 and i == submit[depth - 1] == submit[depth - 2]:
            continue
        submit[depth] = i
        dfs(
            ans,
            submit,
            depth + 1,
            ans_count + (1 if ans[depth] == i else 0),
        )
        submit[depth] = 0


ans = list(map(int, input().split()))

submit = [0] * 10
count = 0
dfs(ans, submit, 0, 0)

print(count)
