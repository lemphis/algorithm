import sys

input = sys.stdin.readline


def dfs(depth, candidate, levels):
    global N, L, R, X, candidates
    total = sum(candidate)
    if total > R:
        return

    if depth == N:
        if len(candidate) > 1 and total >= L and candidate[-1] - candidate[0] >= X:
            candidates.append(candidate)
        return

    dfs(depth + 1, candidate, levels)
    dfs(depth + 1, [*candidate, levels[depth]], levels)


N, L, R, X = map(int, input().split())
levels = list(map(int, input().split()))

levels.sort()

candidates = []
dfs(0, [], levels)

print(len(candidates))
