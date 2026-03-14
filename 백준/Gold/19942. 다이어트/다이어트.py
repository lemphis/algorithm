import sys

input = sys.stdin.readline


def dfs(choices, idx):
    global ans_total, ans_idxes

    if len(choices) == N:
        if is_satisfied(choices):
            total = sum(choice[4] for choice in choices)
            if ans_total > total:
                ans_total = total
                ans_idxes = [choice[5] for choice in choices]
        return

    if is_satisfied(choices):
        total = sum(choice[4] for choice in choices)
        if ans_total > total:
            ans_total = total
            ans_idxes = [choice[5] for choice in choices]
        return

    for i in range(idx, N):
        if not visited[i]:
            visited[i] = True
            choices.append([*ingredients[i], i + 1])
            dfs(choices, i + 1)
            visited[i] = False
            choices.pop()


def is_satisfied(choices):
    if not choices:
        return False

    total = [sum(col) for col in zip(*choices)][:-1]

    return all(total[i] >= standards[i] for i in range(4))


N = int(input())
standards = list(map(int, input().split()))
ingredients = [list(map(int, input().split())) for _ in range(N)]

visited = [False] * N
ans_total = float("inf")
ans_idxes = []

dfs([], 0)

print(ans_total if ans_total < float("inf") else -1)
if ans_total < float("inf"):
    print(*ans_idxes, sep=" ")
